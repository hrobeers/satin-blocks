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
(setq satin-keywords '("OP_NOP" "OP_IF" "OP_NOTIF" "OP_ELSE" "OP_ENDIF"
                       "OP_VERIFY" "OP_EQUAL" "OP_EQUALVERIFY"
                       "OP_RETURN") )
(setq satin-types '("OP_RIPEMD160" "OP_SHA1" "OP_SHA256" "OP_HASH160" "OP_HASH256"
                    "OP_CODESEPARATOR"
                    "OP_CHECKSIG" "OP_CHECKSIGVERIFY" "OP_CHECKMULTISIG" "OP_CHECKMULTISIGVERIFY"))
(setq satin-constants '("OP_0" "OP_1" "OP_2" "OP_3" "OP_4" "OP_5" "OP_6" "OP_7" "OP_8"
                        "OP_9" "OP_10" "OP_11" "OP_12" "OP_13" "OP_14" "OP_15" "OP_16"
                        "OP_TRUE" "OP_FALSE"
                        "OP_PUSHDATA1" "OP_PUSHDATA2" "OP_PUSHDATA4"
                        "OP_1NEGATE"))
(setq satin-events '("OP_CHECKLOCKTIMEVERIFY" "OP_CHECKSEQUENCEVERIFY"))
(setq satin-functions '("OP_TOALTSTACK" "OP_FROMALTSTACK" "OP_IFDUP" "OP_DEPTH"
                        "OP_DROP" "OP_DUP" "OP_NIP" "OP_OVER" "OP_PICK"
                        "OP_ROLL" "OP_ROT" "OP_SWAP" "OP_TUCK"
                        "OP_2DROP" "OP_2DUP" "OP_3DUP" "OP_2OVER" "OP_2ROT" "OP_2SWAP"
                        "OP_SIZE" "OP_1ADD" "OP_1SUB" "OP_NEGATE" "OP_ABS" "OP_NOT" "OP_0NOTEQUAL"
                        "OP_ADD" "OP_SUB" "OP_BOOLAND" "OP_BOOLOR"
                        "OP_NUMEQUAL" "OP_NUMEQUALVERIFY" "OP_NUMNOTEQUAL"
                        "OP_LESSTHAN" "OP_GREATERTHAN" "OP_LESSTHANOREQUAL" "OP_GREATERTHANOREQUAL"
                        "OP_MIN" "OP_MAX" "OP_WITHIN"))

;; generate regex string for each category of keywords
(setq satin-keywords-regexp (regexp-opt satin-keywords 'words))
(setq satin-type-regexp (regexp-opt satin-types 'words))
(setq satin-constant-regexp (regexp-opt satin-constants 'words))
(setq satin-event-regexp (regexp-opt satin-events 'words))
(setq satin-functions-regexp (regexp-opt satin-functions 'words))

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

;;;###autoload
(define-derived-mode satin-mode fundamental-mode "satin"
  "major mode for editing satoshi scripts."
  ;; code for syntax highlighting
  (setq font-lock-defaults '((satin-font-lock-keywords))))

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
