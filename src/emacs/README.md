satin-emacs
===========

Emacs mode for satin-blocks itegration.

### Usage

![emacs-mode.el](../../docs/gifs/satin-emacs.gif)

### Installation

satin-mode depends on auto-complete-mode for auto-completion.
Contributions for company-mode compatibility are welcome.

Place satin-mode.el in your load path e.g.

```(add-to-list 'load-path "~/.emacs.d/manual/satin/")```

Load satin-mode and auto-complete dictionaries

```(require 'satin-mode)```

For auto-completion, add [dict/satin-mode](dict/satin-mode) to a dictionary directory e.g.

```
(add-to-list 'ac-dictionary-directories "~/.emacs.d/manual/satin/dict/")
(add-to-list 'ac-modes 'satin-mode)
```

Make emacs load satin-mode automatically for files with *.satin extension.

```(add-to-list 'auto-mode-alist '("\\.satin\\'" . satin-mode))```