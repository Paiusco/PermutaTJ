FROM ubuntu:devel as platform

RUN apt update -y && apt upgrade -y && \
    apt install -y --no-install-recommends \ 
        cmake \
        cppcheck \
        ninja-build \
        pip \
        g++ && \
    apt autoremove -y && \
    rm -rf /var/lib/apt/lists/* && \
    pip install --upgrade pip setuptools && \
    pip install -U conan && \
    mkdir -p /root/permutatj/

COPY . /root/permutatj/