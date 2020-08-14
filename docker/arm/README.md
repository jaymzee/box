# exploring arm processor architecture

## To enable other exec formats in docker containers run:
```
$ docker run --rm --privileged multiarch/qemu-user-static --reset -p yes
```

## add the followin flags to get gdb to work
```
    --cap-add=SYS_PTRACE --security-opt seccomp=unconfined
```


## start a new container for Alpine Linux on arm32v7
```
$ docker run -it -v /c/Users/James/source/box/docker/arm:/mnt/code -h arm1 arm32v7/alpine 
```
