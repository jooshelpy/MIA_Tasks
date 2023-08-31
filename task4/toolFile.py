"""
File: toolFile.py
Author: Youssef Ahmed Kamel
Description: this file contains the Weapon and Shield class 
Date : [25/8/2023]

"""


# Represents a weapon used by villains
class Weapon:
    def __init__(self, energy_cost, damage):
        self.damage = damage # Damage inflicted by the weapon
        self.energy_cost = energy_cost # Energy cost to use the weapon

# Represents a shield used by villains
class Shield:
    def __init__(self, energy_cost, save_percentage):
        self.save_percentage = save_percentage # Percentage of damage reduced by the shield
        self.energy_cost = energy_cost # Energy cost to use the shield

