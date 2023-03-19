{$CLEO .cs}

script_name 'ARMOUR' 

:ARMOUR_11
wait 0 
if and
  Player.Defined($PLAYER_CHAR)
  Actor.Driving($PLAYER_ACTOR)
jf @ARMOUR_11 
wait 0 
1@ = Actor.CurrentCar($PLAYER_ACTOR)
if 
0448:   actor $PLAYER_ACTOR in_car 1@ 
jf @ARMOUR_11 

:ARMOUR_67
wait 0 
Car.SetImmunities(1@, True, True, True, True, True)
0A30: repair_car 1@ 
if 
81F4:   not car 1@ flipped 
jf @ARMOUR_172 
wait 0 
if 
0448:   actor $PLAYER_ACTOR in_car 1@ 
jf @ARMOUR_137 
jump @ARMOUR_67 

:ARMOUR_137
wait 0 
Car.SetImmunities(1@, False, False, False, False, False)
Car.RemoveReferences(1@)
wait 0 
jump @ARMOUR_11 

:ARMOUR_172
wait 0 
if and
01F4:   car 1@ flipped 
81F3:   not car 1@ in_air 
jf @ARMOUR_11 
07DB: set_car 1@ rotation_velocity_XYZ 0.0 1.5 0.0 through_center_of_mass 
jump @ARMOUR_11 
