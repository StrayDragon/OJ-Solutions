# ---
# id = B1031
# title = 查验身份证
# score = 15
# categories = 字符串
# tags = kmp, string
# ---
import tempfile

fp = tempfile.TemporaryFile()
fp.write(b'Hello world!')

fp.seek(0)
fp.read()

fp.close()

with tempfile.TemporaryFile() as fp:
    fp.write(b'Hello world!')
    fp.seek(0)
    fp.read()

with tempfile.TemporaryDirectory() as tmpdirname:
    print('created temporary directory', tmpdirname)
