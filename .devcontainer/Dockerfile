FROM debian:bookworm-slim

# 1. Dependencies
RUN apt-get update && apt-get install -y \
    automake \
    bison \
    build-essential \
    ccache \
    flex \
    gawk \
    gettext \
    git \
    gtk-doc-tools \
    libc6-dev \
    libgmp3-dev \
    libmpc-dev \
    libmpfr-dev \
    libsdl1.2-dev \
    libtool-bin \
    sudo \
    texinfo \
    wget \
    zip \
    && rm -rf /var/lib/apt/lists/*

# 2. Fix libtool
RUN ln -s /usr/bin/libtoolize /usr/bin/libtool || true

# 3. Create user first, then fix permissions
RUN useradd -m -s /bin/bash rockbox \
    && echo "rockbox ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# 4. Pre-create dirs with correct permissions as root
RUN mkdir -p /tmp/rbdev-dl /tmp/rbdev-build /home/rockbox/toolchains \
    && chmod 777 /tmp/rbdev-dl /tmp/rbdev-build \
    && chown -R rockbox:rockbox /home/rockbox

USER rockbox
WORKDIR /home/rockbox

# 5. Clone Rockbox
RUN git clone --depth=1 git://git.rockbox.org/rockbox rockbox

WORKDIR /home/rockbox/rockbox/tools

# 6. Run rockboxdev.sh (installs to /usr/local/bin via sudo)
ENV RBDEV_TARGET=a
ENV RBDEV_DOWNLOAD=/tmp/rbdev-dl
ENV RBDEV_BUILD=/tmp/rbdev-build

RUN chmod +x rockboxdev.sh && ./rockboxdev.sh

WORKDIR /home/rockbox/rockbox