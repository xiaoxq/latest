FROM nvidia/cuda:10.1-runtime-ubuntu18.04

# Install basic tools.
RUN apt update && apt install -y curl git sudo

# Install bazel.
RUN echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | \
        tee /etc/apt/sources.list.d/bazel.list && \
    curl https://bazel.build/bazel-release.pub.gpg | apt-key add - && \
    apt update && apt install -y bazel

# Add solo user.
RUN adduser --disabled-password --force-badname --gecos '' "aaron" && \
    usermod -aG sudo "aaron" && \
    echo '%sudo ALL=(ALL) NOPASSWD:ALL' | tee -a /etc/sudoers

WORKDIR /latest
USER aaron

COPY entrypoint.sh /home/entrypoint.sh
ENTRYPOINT [ "/home/entrypoint.sh" ]
