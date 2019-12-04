FROM nvidia/cuda:10.1-runtime-ubuntu18.04

# Install basic tools.
RUN apt update && apt install -y git sudo wget

# Add solo user.
RUN adduser --disabled-password --force-badname --gecos '' "aaron" && \
    usermod -aG sudo "aaron" && \
    echo '%sudo ALL=(ALL) NOPASSWD:ALL' | tee -a /etc/sudoers

COPY installers/install_bazel.sh /tmp/
RUN bash /tmp/install_bazel.sh

# Required libs.
RUN apt install -y libcurl4-openssl-dev libcurlpp-dev

USER aaron
COPY installers/install_conda.sh /tmp/
RUN bash /tmp/install_conda.sh

WORKDIR /latest
COPY entrypoint.sh /home/entrypoint.sh
ENTRYPOINT [ "/home/entrypoint.sh" ]
