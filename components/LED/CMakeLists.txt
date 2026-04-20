idf_component_register(
    SRCS "LED.c"                  # 源文件（相对于 CMakeLists.txt 的位置）
    INCLUDE_DIRS "."       # 头文件目录（相对于 CMakeLists.txt 的位置，这里是 components/LED）
    REQUIRES driver esp_driver_gpio
              # 依赖的组件（必须包含 driver，才能找到 driver/gpio.h）
)