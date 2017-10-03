satin-shell
===========

satin-shell is a simple interactive shell created for educational purposes.
Due to lack of advanced features, it is meant to get replaced as default interpreter.

Simple usage example of satin-shell:

![satin-shell 0.1](../../docs/gifs/satin-shell.gif)

```
satin-shell 0.1
satin-0.1$ OP_1 OP_1 OP_EQUALVERIFY
Success
satin-0.1$ op_1 Op_1 Op_equalVerIfy
Success
satin-0.1$ 1 1 equalverify
Success
satin-0.1$ 1 2 equalverify
Script failed an OP_EQUALVERIFY operation
satin-0.1$ 0x12abef 0x5632 equalverify
Script failed an OP_EQUALVERIFY operation
satin-0.1$ 0x123456 dup equalverify
Success
satin-0.1$
```

Looking at the few lines of [satin-shell code](satin-shell.sh) illustrates the UNIX principles of simple building blocks.