"""
File: battle.py
Author: Youssef Ahmed Kamel
Description: this file contains air battlefield class
Date : [25/8/2023]

"""

import random
from villianFile import Gru, Vector

# Represents the air battlefield where the battle takes place
class Battle:
    def __init__(self):
        self.villains = [Gru(), Vector()]

    def play_round(self):
        for villain in self.villains:
            action = random.choice(['shield', 'weapon'])
            if action  == "shield":
                villain.use_shield()
                print(f"{villain.name} is using shield: {villain.shield.__class__.__name__}")
            else:
                opponent = [v for v in self.villains if v != villain][0]
                villain.use_weapon(opponent)
                print(f"{villain.name} is using weapon against {opponent.name}.")    

    def start_game(self):
        round_number = 1
        while all(v.health > 0 for v in self.villains):
            print(f"Round {round_number}")
            self.play_round()
            round_number += 1
            print("Villain Status:")
            for villain in self.villains:
                print(f"{villain.name} - Health: {villain.health}, Energy: {villain.energy:.2f}")

if __name__ == "__main__":
    battlefield = Battle()
    battlefield.start_game()