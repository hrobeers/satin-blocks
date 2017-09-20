satin-shell
===========

satin-shell is a simple interactive shell created for educational purposes.
Due to lack of advanced features, it is meant to get replaced as default interpreter.

Simple usage example of satin-shell:
```
satin-shell 0.1
satin-0.1$ OP_1 OP_2 OP_EQUALVERIFY
Script failed an OP_EQUALVERIFY operation
satin-0.1$ OP_3 OP_3 OP_EQUALVERIFY
Success
satin-0.1$ 0x1a2b3c OP_DUP OP_EQUALVERIFY
Success
satin-0.1$
```

Looking at the satin-shell code illustrates the UNIX principles of simple building blocks.