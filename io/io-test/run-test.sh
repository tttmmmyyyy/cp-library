fix build
cat input.txt | ./a.out

# 文字列のscanfの正しさを確認するときに使う
# ただし、ValgrindはAVX-512命令に対応していないので、AVX-512命令が使われないようなコードに書き換えないと通らない
# cat input.txt | valgrind ./a.out
