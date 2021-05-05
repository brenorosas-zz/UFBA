#lang racket

(define l1 '(3 4 5 6))

(define l2 '((a) b c (d e f)))

(define p1 '(a . b))

(define p2 '(a . (b)))

(define l4 ' ( () () () () ) )

(define l6 (append l1 l1))

(define l7 (list 'a 'b 'c))

(define b 14)

(define l8 (list 'a b 'c))
  
(define f1 (lambda (x) (* x x)))

(define f2 (lambda (x y) (+ y (* x x))))

(define f3 (lambda (x y z) (* (+ x y) z)))

(define (lnum? l)
  (cond
    [(null? l) #t]
    [(not (number? (first l))) #f]
    [else (lnum (rest l))]
    ))

(define (soma l)
  (if (null? l)
      0
      (+ (first l) (soma (rest l)))
      ))