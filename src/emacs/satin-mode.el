;;; satin-mode.el --- major mode for editing satoshi scripts -*- coding: utf-8; lexical-binding: t; -*-

;; Copyright © 2017, by hrobeers

;; Author: hrobeers (https://github.com/hrobeers)
;; Created: 26 Sept 2017
;; Keywords: languages
;; Homepage: https://github.com/hrobeers/satin-blocks

;; This file is not part of GNU Emacs.

;;; License:

;; You can redistribute this program and/or modify it under the terms of the GNU General Public License version 3.

;;; Commentary:

;; Major mode for editing satoshi scripts

;; full doc on how to use here


;;; Code:

;; define several category of keywords
(setq satin-keywords '("NOP" "IF" "NOTIF" "ELSE" "ENDIF"
                       "VERIFY" "EQUAL" "EQUALVERIFY"
                       "RETURN") )
(setq satin-types '("RIPEMD160" "SHA1" "SHA256" "HASH160" "HASH256"
                    "CODESEPARATOR"
                    "CHECKSIG" "CHECKSIGVERIFY" "CHECKMULTISIG" "CHECKMULTISIGVERIFY"))
(setq satin-constants '("0" "1" "2" "3" "4" "5" "6" "7" "8"
                        "9" "10" "11" "12" "13" "14" "15" "16"
                        "TRUE" "FALSE"
                        "PUSHDATA1" "PUSHDATA2" "PUSHDATA4"
                        "1NEGATE"))
(setq satin-events '("CHECKLOCKTIMEVERIFY" "CHECKSEQUENCEVERIFY"))
(setq satin-functions '("TOALTSTACK" "FROMALTSTACK" "IFDUP" "DEPTH"
                        "DROP" "DUP" "NIP" "OVER" "PICK"
                        "ROLL" "ROT" "SWAP" "TUCK"
                        "2DROP" "2DUP" "3DUP" "2OVER" "2ROT" "2SWAP"
                        "SIZE" "1ADD" "1SUB" "NEGATE" "ABS" "NOT" "0NOTEQUAL"
                        "ADD" "SUB" "BOOLAND" "BOOLOR"
                        "NUMEQUAL" "NUMEQUALVERIFY" "NUMNOTEQUAL"
                        "LESSTHAN" "GREATERTHAN" "LESSTHANOREQUAL" "GREATERTHANOREQUAL"
                        "MIN" "MAX" "WITHIN"))

;; generate regex string for each category of keywords
(setq satin-keywords-regexp (concat "\\(OP_\\)?" (regexp-opt satin-keywords 'words)))
(setq satin-type-regexp (concat "\\(OP_\\)?" (regexp-opt satin-types 'words)))
(setq satin-constant-regexp (concat "\\(OP_\\)?" (regexp-opt satin-constants 'words)))
(setq satin-event-regexp (concat "\\(OP_\\)?" (regexp-opt satin-events 'words)))
(setq satin-functions-regexp (concat "\\(OP_\\)?" (regexp-opt satin-functions 'words)))

;; create the list for font-lock.
;; each category of keyword is given a particular face
(setq satin-font-lock-keywords
      `(
        (,satin-type-regexp . font-lock-type-face)
        (,satin-constant-regexp . font-lock-constant-face)
        (,satin-event-regexp . font-lock-builtin-face)
        (,satin-functions-regexp . font-lock-function-name-face)
        (,satin-keywords-regexp . font-lock-keyword-face)
        ;; note: order above matters, because once colored, that part won't change.
        ;; in general, longer words first
        ))

;; comment syntax
(defvar satin-mode-syntax-table nil "Syntax table for `satin-mode'.")
(setq satin-mode-syntax-table
      (let ( (synTable (make-syntax-table)))
        ;; python style comment: “# …”
        (modify-syntax-entry ?# "<" synTable)
        (modify-syntax-entry ?\n ">" synTable)
        synTable))

;;;###autoload
(define-derived-mode satin-mode fundamental-mode "satin"
  "major mode for editing satoshi scripts."
  ;; code for syntax highlighting
  (set (make-local-variable 'font-lock-defaults)
     '(satin-font-lock-keywords nil t)))

;; clear memory. no longer needed
(setq satin-keywords nil)
(setq satin-types nil)
(setq satin-constants nil)
(setq satin-events nil)
(setq satin-functions nil)

;; clear memory. no longer needed
(setq satin-keywords-regexp nil)
(setq satin-types-regexp nil)
(setq satin-constants-regexp nil)
(setq satin-events-regexp nil)
(setq satin-functions-regexp nil)

;; add the mode to the `features' list
(provide 'satin-mode)

(defun satin-eval ()
  "Evaluate the current satin buffer."
  (when (eq major-mode 'satin-mode)
    (shell-command (format "satin-compile %s | satin-run -t" buffer-file-name))))

(add-hook 'after-save-hook #'satin-eval)

;;; satin-mode.el ends here
