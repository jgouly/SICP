(define zero
  (lambda (f)
    (lambda (x)
      x)))

(define add-1
  (lambda (n)
    (lambda (f)
      (lambda (x)
	(f ((n f) x))))))

; Substitution
(define one (add-1 zero))

(define one ((lambda (n) (lambda (f) (lambda (x) (f ((n f) x))))) zero))

(define one (lambda (f) (lambda (x) (f ((zero f) x)))))

(define one (lambda (f) (lambda (x) (f (((lambda (f) (lambda (x) x)) f) x)))))

(define one (lambda (f) (lambda (x) (f ((lambda (x) x) x)))))

(define one (lambda (f) (lambda (x) (f x))))

; Church add

(define church-add
  (lambda (n m)
    (lambda (f)
      (lambda (x)
	((n f) ((m f) x))))))
