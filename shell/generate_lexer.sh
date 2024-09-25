# This script generates the lexer lookup tables
# 
# @file shell/generate_lexer.sh
#
# @author Jacob Smith

# Remove the old lexer
rm include/nami/lexer_lut.h #> /dev/null

###########################
# Construct the new lexer #
###########################

# 
printf "/** \\n * Generated nami lexer\n * \n * @file nami/lexer_lut.h\n**/\n\n// Header guard\n#pragma once\n\n// Data\n" > include/nami/lexer_lut.h

# 

# Construct the keywords lookup table
printf "const char *_p_keywords" >> include/nami/lexer_lut.h
cat resources/lexer/keywords | ./build/hash_optimal crc >> include/nami/lexer_lut.h

# Construct the operators lookup table
printf "const char *_p_operators" >> include/nami/lexer_lut.h
cat resources/lexer/operators | ./build/hash_optimal crc >> include/nami/lexer_lut.h

# Construct the separators lookup table
printf "const char *_p_separators" >> include/nami/lexer_lut.h
cat resources/lexer/separators | ./build/hash_optimal crc >> include/nami/lexer_lut.h