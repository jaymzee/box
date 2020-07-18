enable other exec formats in docker
    docker run --rm --privileged multiarch/qemu-user-static --reset -p yes

mount local folder in container
    docker run -it -v /c/Users/James/source/box/docker/mips:/mnt/code mips64le/busybox
    docker run -it -v /c/Users/James/source/box/docker/mips:/mnt/code muslcc/x86_64:mips64el-linux-musl
