(define (pascal row col)
  (cond 
   ((= 1 row) 1)
   ((= 1 col) 1)
   ((= row col) 1)
   (else (let ((r (- row 1)))
	   (+ (pascal r (- col 1))
	      (pascal r col))))))