<?php  if (!$node->status) { ?>
    <div class="unpublished" style="background-color:#C0392B; text-align:center; color:#fff"> <?php print t('Unpublished'); ?> </div>
  <?php } ?>
<div id="node-<?php print $node->nid;?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($picture): print $user_picture; endif; ?>
  <?php print render($title_prefix); ?>
  <?php if ($page == 0) { ?>
    <?php if ($title) { ?>
      <h2 <?php print $title_attributes; ?>><a href="<?php print $node_url?>"><?php print $title?></a></h2>
    <?php }; ?>
  <?php }; ?>
  <?php print render($title_suffix); ?>
  <?php if ($submitted) { ?>
    <span class="submitted"><?php print $submitted?></span> 
  <?php }; ?>
  <div class="content">
    <?php print $content_attributes?>
    <div class="col-sm-12">
      <div class="pp-container">
        <div>      
              <!-- Add this on line (div) above and Description before switching to the PP         <div class="pp-header">   -->
          
          <?php //  print "Description"; ?>   

        </div>

        <div class="pp-body">
          <?php print render($content['body']['#object']->body['und'][0]['value']);?>
        </div>
      </div>
    </div>


<!-- Blocks from View Primary page content  -->
<!-- Uncomment when I enable the view  -->

<!--  
    <div class="col-sm-6">
      <div class="pp-container">
        <div class="pp-header">
          <?php print "Security Attributes"; ?>
        </div>
        <div class="pp-body">
          <?php print views_embed_view('primary_page_content_', 'block'); ?>
        </div>
      </div>
    </div>
      <div class="col-sm-6">
      <div class="pp-container">
        <div class="pp-header">
          <?php print "Forum Topics"; ?>
        </div>
        <div class="pp-body">
          <?php print views_embed_view('primary_page_content_', 'block_1'); ?>
        </div>
      </div>
    </div>
    <div class="col-sm-6">
      <div class="pp-container">
        <div class="pp-header">
          <?php print "Item Keys"; ?>
        </div>
        <div class="pp-body">
          <?php print views_embed_view('primary_page_content_', 'block_2'); ?>
        </div>
      </div>
    </div>
    <div class="col-sm-6">
      <div class="pp-container">
        <div class="pp-header">
          <?php print "Videos"; ?>
        </div>
        <div class="pp-body">
          <?php print views_embed_view('primary_page_content_', 'block_3'); ?>
        </div>
      </div>
    </div>
  </div>
  <div class="clearfix clear"></div>

  -->
  
  <?php if (!empty($content['links']['node']['#links']) || !empty($content['links']['comment']['#links']) || !empty($content['links']['blog']['#links'])): ?>
    <div class="links"><?php print render($content['links']); ?></div>
  <?php endif; ?>
  <?php if ($content['comments'] && ($page)) { ?>
    <?php print render($content['comments']); ?>
  <?php }; ?>
</div>