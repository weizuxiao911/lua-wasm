
emcc \
  -s WASM=1 \
  -I lua-5.4.0/src \
  $(find lua-5.4.0/src -name "*.c" ! -name "luac.c") \
  lua.c \
  -o lua.js \
  -s EXPORTED_FUNCTIONS='["_main", "_lua"]' \
  -s EXPORTED_RUNTIME_METHODS="['ccall', 'cwrap', 'FS']" 