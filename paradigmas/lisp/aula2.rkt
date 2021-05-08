#lang racket
(define (conte* e lg)
  (cond
    [(null? lg) 0]
    [(list? (first lg))
     (+ (conte* e (first lg))
        (conte* e (rest lg)))]
    [(eqv? e (first lg))
     (+ 1
        (conte* e (rest lg)))]
    [else
     (conte* e (rest lg))]
    ))

(define (substitui* o n lg)
  (cond
    [(null? lg) empty]
    [(list? (first lg))
     (cons (substitui* o n(first lg))
           (substitui* o n (rest lg)))]
     [(eqv? o (first lg))
      (cons n
            (substitui* o n (rest lg)))]
     [else
      (cons (first lg)
            (substitui* o n (rest lg)))]
     ))

(define (rmember-um-f e lg)
  (rest (rmember-um e lg)))
(define (rmember-um e lg)
  (cond
    [(null? lg) (cons #f empty)]
    [(list? (first lg))
     (let ([r-cabeca (rmember-um e (first lg))])
       (if (first r-cabeca)
           (cons #t
                 (cons (rest r-cabeca)
                       (rest lg)))
           (let ([r-cauda (rmember-um e (rest lg))])
             (cons (first r-cauda)
                   (cons (first lg)
                         (rest r-cauda))))))]
     [(eqv? e (first lg)) (cons #t (rest lg))]
     [else
      (let ([r-cauda (rmember-um e (rest lg))])
        (cons (first r-cauda)
              (cons (first lg)
                    (rest r-cauda))))]
     ))
     
                                    