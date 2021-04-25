idf_component_register( SRCS "mc_cmd_aac.c"
                        INCLUDE_DIRS .
                        REQUIRES
                            console
                            mc_aac_decoder
                            mc_assert)
