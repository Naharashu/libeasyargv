# libeasyargv
 
Its a simple library for managing program arguments for C++

## Compiling 

```
git clone https://github.com/Naharashu/libeasyargv.git
cd libeasyargv
make && make install
```

## Testing

```
g++ example.cpp -L. -leasyargv -o test
./test -n 2
./test -a -v
./test -v
./test -a -n 4 -v
```
