################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ButtonSetup.obj: ../ButtonSetup.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --use_hw_mpy=none --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/cuest/OneDrive/Documents/Code Composer/LAB3_HardwarePWM_FR2311" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --advice:hw_config=all --define=__MSP430FR2311__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="ButtonSetup.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

TimerB0Setup.obj: ../TimerB0Setup.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --use_hw_mpy=none --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/cuest/OneDrive/Documents/Code Composer/LAB3_HardwarePWM_FR2311" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --advice:hw_config=all --define=__MSP430FR2311__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="TimerB0Setup.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

TimerB1Setup.obj: ../TimerB1Setup.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --use_hw_mpy=none --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/cuest/OneDrive/Documents/Code Composer/LAB3_HardwarePWM_FR2311" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --advice:hw_config=all --define=__MSP430FR2311__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="TimerB1Setup.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/bin/cl430" -vmspx --use_hw_mpy=none --include_path="C:/ti/ccsv8/ccs_base/msp430/include" --include_path="C:/Users/cuest/OneDrive/Documents/Code Composer/LAB3_HardwarePWM_FR2311" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-msp430_18.1.2.LTS/include" --advice:power=all --advice:hw_config=all --define=__MSP430FR2311__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="main.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


