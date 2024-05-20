# Primal++

Computes prime numbers using trial division.

## Preview

![2024-05-19-184036](https://github.com/fiffy326/primal-plus-plus/assets/22841956/acf339c6-ac04-412b-848b-cc4f39291fd2)

![2024-05-19-184053](https://github.com/fiffy326/primal-plus-plus/assets/22841956/9a36b362-f340-430b-98d8-c2f5d45250b3)

## Installation

```sh
git clone https://github.com/fiffy326/primal-plus-plus
cd primal-plus-plus
make
sudo make install
```

```sh
# Other compilation options:
make gcc
make gcc-static
make clang
make clang-static
```
## Dependencies

Compilation is done with clang by default for performance reasons.

You may also build with gcc if you prefer.

The performance boost with clang is about 2.75x compared to gcc.


Hyperfine is also required to use the `make benchmark` command.
