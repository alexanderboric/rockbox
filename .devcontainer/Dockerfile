FROM --platform=linux/amd64 debian:bookworm-slim

# 1. Install necessary build tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential git texinfo flex bison libgmp-dev libmpfr-dev \
    libmpc-dev libisl-dev curl python3 perl zip unzip libncurses5-dev \
    wget automake libtool libtool-bin autoconf patch pkg-config gperf \
    && rm -rf /var/lib/apt/lists/*

# 2. Set up workspace
WORKDIR /home/rockbox/rockbox

# 3. Automation variables (matches Rockbox's expected structure)
ENV PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"