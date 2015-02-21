# Controlando un brazo robot con protocoder

Vamos a desarrollar un interface en protocoder para controlar desde el móvil un brazo robot de 6 DOF (grados de libertad): cadera, hombro, codo, giro de muñeca, inclinación de muñeca y pinza (en inglés, que se utiliza en el código: hip, soulder, elbow, wrist roll, writs pich, grip)

Se ha elegido protocoder porque permite una interacción muy sencilla con el móvil facilitando el desarrollo y las pruebas.

Tendremos un código en arduino que recibirá los comandos: Se basa en el código calibraServo (en cuanto a usar los límites y permitir el control analógico ) y un script para recibir comandos desde el móvil usando protocoder.

Inspirado, y aprendiendo del [tutorial](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Introduction_to_Object-Oriented_JavaScript) de @victornomad 

Aprendiendo/recordando sobre clases en javascript de [este tutorial](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Introduction_to_Object-Oriented_JavaScript)