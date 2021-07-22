FROM ubuntu:18.04

RUN apt update && apt install -y npm g++ git libelf-dev libcap-dev
RUN npm install -g @bazel/bazelisk

RUN git clone https://github.com/teslamotors/perf_data_converter.git /usr/src/perf_data_converter
WORKDIR /usr/src/perf_data_converter

RUN bazel build src:perf_to_profile

ENTRYPOINT [ "bazel", "test", "src:all" ]