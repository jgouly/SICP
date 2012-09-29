(defun last-pair (lst)
  (cond
    ((equal lst '()) lst)
    ((equal (cdr lst) '()) lst)
    (t (last-pair (cdr lst)))))
