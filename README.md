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
<<<<<<< HEAD
g++ example.cpp -L. -leasyargv -o test
=======
g++ example.cpp -o test -leasyargv
>>>>>>> b846aade5ffbc5d15f555f25f60d3de40e0f718e
./test -n 2
./test -a -v
./test -v
./test -a -n 4 -v
```
