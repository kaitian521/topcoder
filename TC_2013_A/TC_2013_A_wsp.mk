.PHONY: clean All

All:
	@echo "----------Building project:[ TC_2013_A - Debug ]----------"
	@$(MAKE) -f  "TC_2013_A.mk"
clean:
	@echo "----------Cleaning project:[ TC_2013_A - Debug ]----------"
	@$(MAKE) -f  "TC_2013_A.mk" clean
