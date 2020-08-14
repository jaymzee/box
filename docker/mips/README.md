# exploring mips processor architecture

## To enable other exec formats in docker containers run:
```
$ docker run --rm --privileged multiarch/qemu-user-static --reset -p yes
```

## start a very minimal container that executes mips architecture
```
$ docker run -it -v /c/Users/James/source/box/docker/mips:/mnt/code mips64le/busybox
```

## start a new container for compiling C/C++ code to mips architecture
```
$ docker run -it -v /c/Users/James/source/box/docker/mips:/mnt/code muslcc/x86_64:mips64el-linux-musl
```
