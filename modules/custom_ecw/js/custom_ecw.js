jQuery(document).ready(function(){
	jQuery('.vbo-select-all-markup').hide();
	jQuery('.views-field-views-bulk-operations .form-type-checkbox').hide();
	jQuery('.panel-body button[name="op"]').on('click', function(){
		jQuery('.form-type-checkbox input.vbo-select-this-page').trigger('click').trigger('click');	
	});
});