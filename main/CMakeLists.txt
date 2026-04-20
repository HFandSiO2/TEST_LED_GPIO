idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "."
                    REQUIRES LED driver esp_driver_gpio
)
