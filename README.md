# Projet Arduino - Moniteur d'Humidité et de Température

Ce projet Arduino utilise un capteur DHT11 pour surveiller l'humidité et la température de l'environnement. Les données sont affichées sur un écran LCD 16x2. L'utilisateur peut basculer entre l'affichage de l'humidité et de la température en appuyant sur un bouton.

## Composants utilisés
- Capteur DHT11
- Écran LCD 16x2
- Bouton-poussoir
- LED verte, jaune et rouge

## Configuration

### Branchements
- Capteur DHT11 : Broche de données connectée à la broche 2
- Écran LCD : Connecté aux broches 8, 9, 10, 11, 12 et 13
- Bouton-poussoir : Connecté à la broche 3
- LED verte : Connectée à la broche 7
- LED jaune : Connectée à la broche 6
- LED rouge : Connectée à la broche 5

## Fonctionnement
1. Lorsque le bouton est pressé, l'utilisateur peut basculer entre l'affichage de l'humidité et de la température.
2. En fonction de la plage de valeurs mesurées, les LEDs indiquent le niveau d'humidité ou de température.
3. Les données sont affichées sur l'écran LCD.
   
## Photos

![IMG_6293](https://github.com/Matthieumoto/Humidite-Temperature/assets/136125610/26561567-43dc-4a38-9a5d-f2d1399eb691)

![IMG_6294](https://github.com/Matthieumoto/Humidite-Temperature/assets/136125610/2f4628df-e813-4264-9f05-8298cff7c5df)

![IMG_6296](https://github.com/Matthieumoto/Humidite-Temperature/assets/136125610/51e2b3cc-af41-45aa-83b4-00492b68ffab)

## Notes
- Le capteur DHT11 doit être correctement alimenté et les connexions doivent être vérifiées.
- Assurez-vous d'inclure les bibliothèques DHT et LiquidCrystal dans votre environnement Arduino IDE.

## Auteur
Ce projet a été réalisé par **Matthieu_moto**.

N'hésitez pas à contribuer et à améliorer ce projet.

## Licence
Ce projet est sous licence [licence]. Pour plus d'informations, consultez le fichier [LICENSE.md].
