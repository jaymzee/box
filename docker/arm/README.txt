enable other exec formats in docker
    docker run --rm --privileged multiarch/qemu-user-static --reset -p yes

enable flags for gdb to work
    --cap-add=SYS_PTRACE --security-opt seccomp=unconfined

mount local file system folder into container
    docker run -it -v /c/Users/James/source/repos/boxes/docker/arm:/mnt/code arm32v7/alpine 
