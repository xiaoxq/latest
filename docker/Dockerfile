FROM nvidia/cuda:10.2-runtime-ubuntu18.04

# Install basic tools.
RUN apt update && apt install -y cmake git sudo wget

# Add solo user.
RUN adduser --disabled-password --force-badname --gecos '' "aaron" && \
    usermod -aG sudo "aaron" && \
    echo '%sudo ALL=(ALL) NOPASSWD:ALL' | tee -a /etc/sudoers

COPY installers/install_bazel.sh /tmp/
RUN bash /tmp/install_bazel.sh

# Required lib for compiling curlpp.
RUN apt install -y libcurl4-openssl-dev

USER aaron
WORKDIR /latest
COPY entrypoint.sh /home/entrypoint.sh
ENTRYPOINT [ "/home/entrypoint.sh" ]
