(setq flycheck-clang-language-standard "c++17")
(setq flycheck-clang-includes '("~/Documents/call/src/"))
(setq flycheck-clang-includes '("-Wall" "-std=c++17"))


(defun call/MakeFile-test ()
  (interactive)
  (let ((default-directory (projectile-project-root)))
    (compile "make clean test")))

(defun call/MakeFile-comp ()
  (interactive)
  (let ((default-directory (projectile-project-root)))
    (compile "make clean all")))




(global-set-key (kbd "C-c m t") 'call/MakeFile-test)
(global-set-key (kbd "C-c m c") ' all/MakeFile-comp)
