/*
 * Copyright (c) 2016, Google Inc.
 * All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "src/perf_to_profile_lib.h"

#include "src/quipper/base/logging.h"
#include "src/perf_data_converter.h"

int main(int argc, char** argv) {
  std::string input, perfmap, output;
  bool overwriteOutput = false;
  bool allowUnalignedJitMappings = false;
  if (!ParseArguments(argc, const_cast<const char**>(argv), &input, &output,
                      &overwriteOutput, &allowUnalignedJitMappings, &perfmap)) {
    PrintUsage();
    return EXIT_FAILURE;
  }

  uint32_t options = perftools::kNoOptions;
  if (allowUnalignedJitMappings) {
    options |= perftools::ConversionOptions::kAllowUnalignedJitMappings;
  }
  std::string data = ReadFileToString(input);
  std::string pmData = std::string();
  if (perfmap.length() > 1) {
    pmData = ReadFileToString(perfmap);
  }
  const auto profiles = StringToProfiles(data, pmData, perftools::kNoLabels, options);

  // With kNoOptions, all of the PID profiles should be merged into a
  // single one.
  if (profiles.size() != 1) {
    LOG(FATAL) << "Expected profile vector to have one element.";
  }
  const auto& profile = profiles[0]->data;
  std::ofstream outFile;
  CreateFile(output, &outFile, overwriteOutput);
  profile.SerializeToOstream(&outFile);
  return EXIT_SUCCESS;
}
