#!/bin/bash

IMAGE_NAME="permuta-buildagent"

if [ ! "$(docker image inspect -format='{{.State.ExitCode}}' ${IMAGE_NAME})" ]; then
  echo "Docker image not found. Building..."
  docker build -t ${IMAGE_NAME} ../
fi

docker run "${IMAGE_NAME}" /bin/bash -c "cd /root/permutatj; \
  mkdir build && cd build; \
  conan install ..; \
  cmake -S .. -B . -G Ninja -DCMAKE_BUILD_TYPE=Release; \
  cmake --build ."