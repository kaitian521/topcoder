.PHONY: clean All

All:
	@echo "----------Building project:[ TC_SRM_576_A - Debug ]----------"
	@$(MAKE) -f  "TC_SRM_576_A.mk"
clean:
	@echo "----------Cleaning project:[ TC_SRM_576_A - Debug ]----------"
	@$(MAKE) -f  "TC_SRM_576_A.mk" clean
