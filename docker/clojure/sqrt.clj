(ns clojure.examples.sqrt
   (:gen-class))
(def tolerance 0.00001)
(defn fixed-point [f first-guess]
  (defn close-enough? [v1 v2]
    (< (Math/abs (- v1 v2)) tolerance))
  (defn attempt [guess]
    (let [next-guess (f guess)]
      (if (close-enough? guess next-guess)
        next-guess
        (attempt next-guess))))
  (attempt first-guess))
(defn average [x y]
  (/ (+ x y) 2))
(defn average-damp [f]
  #(average % (f %)))
(defn sqrt [x]
  (fixed-point (average-damp #(/ x %)) 1.0))
(println (sqrt 2.0))
(println (Math/sqrt 2.0))
