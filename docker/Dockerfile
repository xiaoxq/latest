FROM nvidia/cuda:10.1-runtime-ubuntu18.04

# Add solo user.
RUN adduser --disabled-password --force-badname --gecos '' "aaron" && \
    usermod -aG sudo "aaron" && \
    echo '%sudo ALL=(ALL) NOPASSWD:ALL' | tee -a /etc/sudoers

# Install basic tools.
RUN apt update && apt install -y git sudo wget

# Install bazel: https://docs.bazel.build/versions/master/install-ubuntu.html
RUN cd /tmp && \
    apt install -y pkg-config zip g++ zlib1g-dev unzip python3 && \
    wget https://github.com/bazelbuild/bazel/releases/download/1.1.0/bazel-1.1.0-installer-linux-x86_64.sh && \
    bash bazel-1.1.0-installer-linux-x86_64.sh && \
    rm bazel-1.1.0-installer-linux-x86_64.sh && \
    echo "source /usr/local/lib/bazel/bin/bazel-complete.bash" >> /home/aaron/.bashrc

WORKDIR /latest
USER aaron

COPY entrypoint.sh /home/entrypoint.sh
ENTRYPOINT [ "/home/entrypoint.sh" ]
