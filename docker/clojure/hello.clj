(ns clojure.examples.hello
   (:gen-class))
(defn square [x]
  (* x x))
(def nums [1 2 3 4 5])
(defn hello-world []
   (println (map square nums)))
(hello-world)
