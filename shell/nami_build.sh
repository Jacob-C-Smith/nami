# Nami compiler
#
# @author Jacob Smith
#
# @file shell/nami_build.sh

##########
# Source #
##########
cat $1 | 

####################
# Lexical analysis #
####################
./build/nami_lexer | 

# Optional: Save the lexer output
tee lexed.nami | 

# Optional: Print the lexer output to standard out
./build/nami_lexer_pretty_printer |

###################
# Syntax analysis #
###################
./build/nami_parser |

# Optional: Save the syntax analyzer output
# tee parsed.nami |

#####################
# Semantic analysis #
#####################
./build/nami_type | 

# Optional: Save the semantic analyzer output
#tee type.nami | 

##############################
# Intermeiate Representation #
##############################
./build/nami_ir | 

# Optional: Save the IR output
#tee ir.nami

#############################
# Machine code optimization #
#############################
./build/nami_optimizer |

# Optional: Save the code optimizer output
#tee ir.nami

###################
# Code generation #
###################

# Save the code generation output
./build/nami_code > $1.elf
