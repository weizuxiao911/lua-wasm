emcc -o3 \
  -I lua-5.4.0/src \
  -I ./src \
  $(find lua-5.4.0/src -name "*.c" ! -name "lua.c"  ! -name "luac.c") \
  $(find ./src -name "*.c") \
  -o vm.js \
  -s EXPORTED_FUNCTIONS='["_main", "_lua", "_ls"]' \
  -s EXPORTED_RUNTIME_METHODS="['ccall', 'cwrap', 'FS', 'ENV',  'PATH']" \
  -s ALLOW_MEMORY_GROWTH=1 \
  -s WASM=1 \
  -s FORCE_FILESYSTEM=1 \
  -s NO_EXIT_RUNTIME=1

# ENVIRONMENT 指定运行环境
# ALLOW_MEMORY_GROWTH 允许内存增长
# FILESYSTEM 启用文件系统
# o3 启用更多优化策略
# EXPORTED_FUNCTIONS 导出函数
# EXPORTED_RUNTIME_METHODS 导出运行时方法
# I 链接依赖
# NO_EXIT_RUNTIME 设置在main函数退出后仍然继续运行
#   -s EXPORT_NAME='VM' \
#   -s MODULARIZE=1 \