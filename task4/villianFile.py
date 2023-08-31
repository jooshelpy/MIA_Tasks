"""
File: villianFile.py
Author: Youssef Ahmed Kamel
Description: this file contains the parent class and its childs
Date : [25/8/2023]

"""


from toolFile import Weapon, Shield
import random

# Base class for all villains
class Villian:
    def __init__(self, name, weapons, shields):
        self.name = name
        self.health = 100
        self.energy = 500
        self.shield = None # The current shield in use
        self.weapons = weapons # List of available weapons
        self.shields = shields  # List of available shields

    def take_damage(self, damage):
        # Calculate the actual damage taken after considering the shield's reduction
        actual_damage = damage - damage * self.Shield.save_percentage
        self.health -= actual_damage

    def use_shields(self):
        # Choose a shield from the available shields and use it for protection
        self.shield = random.choice(self.shields)
        self.energy -= Shield.energy_cost
            
    def use_weapon(self, opponent):
        # Choose a weapon from the available weapons and attack the opponent
        Weapon = random.choice(self.weapons)
        opponent.take_damage(Weapon.damage)
        self.energy -= Weapon.energy_cost

# Define Gru's weapons
freeze_gun = Weapon(50, 11)
electric_prod = Weapon(88, 18)
mega_magnet = Weapon(92, 10)
kalman_missile = Weapon(120, 20)

# Define Gru's shields
energy_projected_barrier = Shield(20, 0.4)
selective_permeability = Shield(50, 0.9)

# Define Vector's weapons
laser_blasters = Weapon(40, 8)
plasma_grenades = Weapon(56, 13)
sonic_resonance_cannon = Weapon(100, 22)

# Define Vector's shields
energy_net_trap = Shield(15, 0.32)
quantum_deflector = Shield(40, 0.8)    

# Gru class inherits from Villain, representing Gru with his weapons and shields
class Gru(Villian):
    def __init__(self):
        weapons = [freeze_gun, electric_prod, mega_magnet, kalman_missile]
        shields = [energy_projected_barrier, selective_permeability]
        super().__init__("Gru", weapons, shields)

# Vector class inherits from Villain, representing Vector with his weapons and shields
class Vector(Villian):
    def __init__(self):
        weapons = [laser_blasters, plasma_grenades, sonic_resonance_cannon]
        shields = [energy_net_trap, quantum_deflector]
        super().__init__("Vector", weapons, shields)      

