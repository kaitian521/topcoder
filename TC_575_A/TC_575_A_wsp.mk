.PHONY: clean All

All:
	@echo "----------Building project:[ TC_575_A - Debug ]----------"
	@$(MAKE) -f  "TC_575_A.mk"
clean:
	@echo "----------Cleaning project:[ TC_575_A - Debug ]----------"
	@$(MAKE) -f  "TC_575_A.mk" clean
