<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  
  

  


  <head>
    <title>
      og_reference_tree.field.inc dans webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree.
     – hug - intranet-tma - Trac
    </title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <!--[if IE]><script type="text/javascript">window.location.hash = window.location.hash;</script><![endif]-->
        <link rel="search" href="/hug/intranet-tma/trac/search" />
        <link rel="help" href="/hug/intranet-tma/trac/wiki/TracGuide" />
        <link rel="alternate" href="/hug/intranet-tma/trac/export/2519/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc" type="text/plain" title="Format original" />
        <link rel="tracwysiwyg.base" href="/hug/intranet-tma/trac" />
        <link rel="start" href="/hug/intranet-tma/trac/wiki" />
        <link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/trac.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/code.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/pygments/trac.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/browser.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/tracwysiwyg/wysiwyg.css" type="text/css" />
        <link rel="tracwysiwyg.stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/trac.css" /><link rel="tracwysiwyg.stylesheet" href="/hug/intranet-tma/trac/chrome/tracwysiwyg/editor.css" />
        <link rel="prev" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc?rev=2214" title="Révision 2214" />
        <link rel="shortcut icon" href="/hug/intranet-tma/trac/chrome/common/trac.ico" type="image/x-icon" />
        <link rel="icon" href="/hug/intranet-tma/trac/chrome/common/trac.ico" type="image/x-icon" />
      <link type="application/opensearchdescription+xml" rel="search" href="/hug/intranet-tma/trac/search/opensearch" title="Rechercher dans hug - intranet-tma - Trac" />
    <script type="text/javascript">
      var _tracwysiwyg={"escapeNewlines":false};
    </script>
    <script type="text/javascript" src="/hug/intranet-tma/trac/chrome/common/js/jquery.js"></script><script type="text/javascript" src="/hug/intranet-tma/trac/chrome/common/js/babel.js"></script><script type="text/javascript" src="/hug/intranet-tma/trac/chrome/common/js/messages/fr.js"></script><script type="text/javascript" src="/hug/intranet-tma/trac/chrome/common/js/trac.js"></script><script type="text/javascript" src="/hug/intranet-tma/trac/chrome/common/js/search.js"></script><script type="text/javascript" src="/hug/intranet-tma/trac/chrome/tracwysiwyg/wysiwyg.js"></script><script type="text/javascript" src="/hug/intranet-tma/trac/chrome/tracwysiwyg/wysiwyg-load.js"></script><script type="text/javascript" src="/hug/intranet-tma/trac/chrome/tracsectionedit/js/tracsectionedit.js"></script>
    <!--[if lt IE 7]>
    <script type="text/javascript" src="/hug/intranet-tma/trac/chrome/common/js/ie_pre7_hacks.js"></script>
    <![endif]-->
    <script type="text/javascript" src="/hug/intranet-tma/trac/chrome/common/js/folding.js"></script>
    <script type="text/javascript">
      jQuery(document).ready(function($) {
        $(".trac-toggledeleted").show().click(function() {
                  $(this).siblings().find(".trac-deleted").toggle();
                  return false;
        }).click();
        $("#jumploc input").hide();
        $("#jumploc select").change(function () {
          this.parentNode.parentNode.submit();
        });
          $('#preview table.code').enableCollapsibleColumns($('#preview table.code thead th.content'));
      });
    </script>
    <link rel="stylesheet" type="text/css" href="/hug/intranet-tma/trac/chrome/site/css/trac.css" />
      <link rel="stylesheet" type="text/css" href="/hug/intranet-tma/trac/chrome/site/css/browser.css" />
   </head>
  <body>
    <div id="banner">
      <div id="header">
        <a id="logo" href="https://projects.clever-age.net/hug/intranet-tma/trac/wiki"><img src="http://www.hug-ge.ch/images/logo_hug.gif" alt="Clever Box HUG" /></a>
      </div>
      <form id="search" action="/hug/intranet-tma/trac/search" method="get">
        <div>
          <label for="proj-search">Recherche :</label>
          <input type="text" id="proj-search" name="q" size="18" value="" />
          <input type="submit" value="Recherche" />
        </div>
      </form>
      <div id="metanav" class="nav">
    <ul>
      <li class="first">Connecté en tant qu'utilisateur fredrik.lahode</li><li><a href="/hug/intranet-tma/trac/logout">Déconnexion</a></li><li><a href="/hug/intranet-tma/trac/prefs">Préférences</a></li><li><a href="/hug/intranet-tma/trac/wiki/TracGuide">Aide / Guide</a></li><li><a href="/hug/intranet-tma/trac/about">À propos de Trac</a></li><li class="last"><a href="/hug/intranet-tma/trac/capassword">Password</a></li>
    </ul>
  </div>
    </div>
    <div id="mainnav" class="nav">
    <ul>
      <li class="first"><a href="/hug/intranet-tma/trac/wiki">Wiki</a></li><li><a href="/hug/intranet-tma/trac/timeline">Activité</a></li><li><a href="/hug/intranet-tma/trac/roadmap">Feuille de route</a></li><li class="active"><a href="/hug/intranet-tma/trac/browser">Explorateur de source</a></li><li><a href="/hug/intranet-tma/trac/report">Voir les tickets</a></li><li><a href="/hug/intranet-tma/trac/newticket">Nouveau ticket</a></li><li><a href="/hug/intranet-tma/trac/search">Recherche</a></li><li class="last"><a href="/hug/intranet-tma/trac/billing">Management</a></li>
    </ul>
  </div>
    <div id="main">
      <div id="ctxtnav" class="nav">
        <h2>Navigation contextuelle</h2>
          <ul>
              <li class="first"><span>&larr; <a class="prev" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc?rev=2214" title="Révision 2214">Révision précédente</a></span></li><li><span class="missing">Révision suivante &rarr;</span></li><li><a href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc?annotate=blame" title="Annoter chaque ligne avec la révision de la dernière modification (ce procédé peut-être coûteux en temps...)">Annoter</a></li><li class="last"><a href="/hug/intranet-tma/trac/log/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc">Journal des révisions</a></li>
          </ul>
        <hr />
      </div>
    <div id="content" class="browser">
          <h1>
<a class="pathentry first" href="/hug/intranet-tma/trac/browser?order=name" title="Aller à la racine du dépôt">source:</a>
<a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory?order=name" title="Voir webfactory">webfactory</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk?order=name" title="Voir trunk">trunk</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites?order=name" title="Voir sites">sites</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all?order=name" title="Voir all">all</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules?order=name" title="Voir modules">modules</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom?order=name" title="Voir custom">custom</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree?order=name" title="Voir entity_reference_tree">entity_reference_tree</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree?order=name" title="Voir og_reference_tree">og_reference_tree</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc?order=name" title="Voir og_reference_tree.field.inc">og_reference_tree.field.inc</a>
<span class="pathentry sep">@</span>
  <a class="pathentry" href="/hug/intranet-tma/trac/changeset/2519" title="Voir la révision 2519">2519</a>
<br style="clear: both" />
</h1>
        <div id="jumprev">
          <form action="" method="get">
            <div>
              <label for="rev">
                Afficher la révision :</label>
              <input type="text" id="rev" name="rev" size="6" />
            </div>
          </form>
        </div>
        <div id="jumploc">
          <form action="" method="get">
            <div class="buttons">
              <label for="preselected">Explorer :</label>
              <select id="preselected" name="preselected">
                <option selected="selected"></option>
                <optgroup label="branches">
                  <option value="/hug/intranet-tma/trac/browser/trunk">trunk</option>
                </optgroup>
              </select>
              <input type="submit" value="Aller" title="Saut direct au chemin préselectionné" />
            </div>
          </form>
        </div>
      <table id="info" summary="Info révision">
        <tr>
          <th scope="col">Révision <a href="/hug/intranet-tma/trac/changeset/2215">2215</a>,
            <span title="1724 octets">1.7 KB</span>
            produite par fredrik.lahode, il y a <a class="timeline" href="/hug/intranet-tma/trac/timeline?from=2014-01-21T13%3A02%3A43%2B01%3A00&amp;precision=second" title="2014-01-21T13:02:43+01:00 dans « Activité »">4 mois</a>
            (<a href="/hug/intranet-tma/trac/changeset/2215/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc">différences</a>)</th>
        </tr>
        <tr>
          <td class="message searchable">
              <p>
Correction entity_reference_tree<br />
</p>
          </td>
        </tr>
      </table>
      <div id="preview" class="searchable">
        
  <table class="code"><thead><tr><th class="lineno" title="Numéros de lignes">Ligne</th><th class="content"> </th></tr></thead><tbody><tr><th id="L1"><a href="#L1">1</a></th><td>&lt;?php</td></tr><tr><th id="L2"><a href="#L2">2</a></th><td></td></tr><tr><th id="L3"><a href="#L3">3</a></th><td>/**</td></tr><tr><th id="L4"><a href="#L4">4</a></th><td> * Implements hook_field_formatter_info().</td></tr><tr><th id="L5"><a href="#L5">5</a></th><td> */</td></tr><tr><th id="L6"><a href="#L6">6</a></th><td>function og_reference_tree_field_formatter_info() {</td></tr><tr><th id="L7"><a href="#L7">7</a></th><td>  return array(</td></tr><tr><th id="L8"><a href="#L8">8</a></th><td>    'og_reference_tree' =&gt; array(</td></tr><tr><th id="L9"><a href="#L9">9</a></th><td>      'label' =&gt; 'OG reference tree',</td></tr><tr><th id="L10"><a href="#L10">10</a></th><td>      'field types' =&gt; array('entityreference'),</td></tr><tr><th id="L11"><a href="#L11">11</a></th><td>      'settings' =&gt; array(</td></tr><tr><th id="L12"><a href="#L12">12</a></th><td>        'token_display_selected' =&gt; '',</td></tr><tr><th id="L13"><a href="#L13">13</a></th><td>        'token_display_unselected' =&gt; '',</td></tr><tr><th id="L14"><a href="#L14">14</a></th><td>        'target_entity' =&gt; 'node',</td></tr><tr><th id="L15"><a href="#L15">15</a></th><td>        'target_id' =&gt; 'target_id',</td></tr><tr><th id="L16"><a href="#L16">16</a></th><td>      ),</td></tr><tr><th id="L17"><a href="#L17">17</a></th><td>    ),</td></tr><tr><th id="L18"><a href="#L18">18</a></th><td>  );</td></tr><tr><th id="L19"><a href="#L19">19</a></th><td>}</td></tr><tr><th id="L20"><a href="#L20">20</a></th><td></td></tr><tr><th id="L21"><a href="#L21">21</a></th><td></td></tr><tr><th id="L22"><a href="#L22">22</a></th><td>/**</td></tr><tr><th id="L23"><a href="#L23">23</a></th><td> * Implements hook_field_formatter_view().</td></tr><tr><th id="L24"><a href="#L24">24</a></th><td> */</td></tr><tr><th id="L25"><a href="#L25">25</a></th><td>function og_reference_tree_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {</td></tr><tr><th id="L26"><a href="#L26">26</a></th><td>  $element = array();</td></tr><tr><th id="L27"><a href="#L27">27</a></th><td></td></tr><tr><th id="L28"><a href="#L28">28</a></th><td>  switch ($display['type']) {</td></tr><tr><th id="L29"><a href="#L29">29</a></th><td>    case 'og_reference_tree':</td></tr><tr><th id="L30"><a href="#L30">30</a></th><td>      if (!empty($items)) {</td></tr><tr><th id="L31"><a href="#L31">31</a></th><td>        $element[] = array(</td></tr><tr><th id="L32"><a href="#L32">32</a></th><td>          '#theme' =&gt; 'entity_reference_tree_list',</td></tr><tr><th id="L33"><a href="#L33">33</a></th><td>          '#data' =&gt; $items,</td></tr><tr><th id="L34"><a href="#L34">34</a></th><td>          '#display' =&gt; $display,</td></tr><tr><th id="L35"><a href="#L35">35</a></th><td>          '#attached' =&gt; array('css' =&gt; array(drupal_get_path('module', 'entity_reference_tree') . '/entity_reference_tree.css', drupal_get_path('module', 'og_reference_tree') . '/og_reference_tree.css')),</td></tr><tr><th id="L36"><a href="#L36">36</a></th><td>        );</td></tr><tr><th id="L37"><a href="#L37">37</a></th><td>      }</td></tr><tr><th id="L38"><a href="#L38">38</a></th><td>      break;</td></tr><tr><th id="L39"><a href="#L39">39</a></th><td>  }</td></tr><tr><th id="L40"><a href="#L40">40</a></th><td></td></tr><tr><th id="L41"><a href="#L41">41</a></th><td>  return $element;</td></tr><tr><th id="L42"><a href="#L42">42</a></th><td>}</td></tr><tr><th id="L43"><a href="#L43">43</a></th><td></td></tr><tr><th id="L44"><a href="#L44">44</a></th><td></td></tr><tr><th id="L45"><a href="#L45">45</a></th><td>/**</td></tr><tr><th id="L46"><a href="#L46">46</a></th><td> * Implements hook_field_formatter_settings_form().</td></tr><tr><th id="L47"><a href="#L47">47</a></th><td> */</td></tr><tr><th id="L48"><a href="#L48">48</a></th><td>function og_reference_tree_field_formatter_settings_form($field, $instance, $view_mode, $form, &amp;$form_state) {</td></tr><tr><th id="L49"><a href="#L49">49</a></th><td>  $display = $instance['display'][$view_mode];</td></tr><tr><th id="L50"><a href="#L50">50</a></th><td>  $settings = $display['settings'];</td></tr><tr><th id="L51"><a href="#L51">51</a></th><td></td></tr><tr><th id="L52"><a href="#L52">52</a></th><td>  $element = array();</td></tr><tr><th id="L53"><a href="#L53">53</a></th><td></td></tr><tr><th id="L54"><a href="#L54">54</a></th><td>  return $element;</td></tr><tr><th id="L55"><a href="#L55">55</a></th><td>}</td></tr><tr><th id="L56"><a href="#L56">56</a></th><td></td></tr><tr><th id="L57"><a href="#L57">57</a></th><td></td></tr><tr><th id="L58"><a href="#L58">58</a></th><td>/**</td></tr><tr><th id="L59"><a href="#L59">59</a></th><td> * Implements hook_field_formatter_settings_summary().</td></tr><tr><th id="L60"><a href="#L60">60</a></th><td> */</td></tr><tr><th id="L61"><a href="#L61">61</a></th><td>function og_reference_tree_field_formatter_settings_summary($field, $instance, $view_mode) {</td></tr><tr><th id="L62"><a href="#L62">62</a></th><td>  $display = $instance['display'][$view_mode];</td></tr><tr><th id="L63"><a href="#L63">63</a></th><td>  $settings = $display['settings'];</td></tr><tr><th id="L64"><a href="#L64">64</a></th><td></td></tr><tr><th id="L65"><a href="#L65">65</a></th><td>  $summary = '';</td></tr><tr><th id="L66"><a href="#L66">66</a></th><td></td></tr><tr><th id="L67"><a href="#L67">67</a></th><td>  return $summary;</td></tr><tr><th id="L68"><a href="#L68">68</a></th><td>}</td></tr></tbody></table>

      </div>
      <div id="help"><strong>Note :</strong> consultez <a href="/hug/intranet-tma/trac/wiki/TracBrowser">TracBrowser</a> pour obtenir de l'aide sur l'utilisation de l'explorateur de sources.</div>
      <div id="anydiff">
        <form action="/hug/intranet-tma/trac/diff" method="get">
          <div class="buttons">
            <input type="hidden" name="new_path" value="/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc" />
            <input type="hidden" name="old_path" value="/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc" />
            <input type="hidden" name="new_rev" />
            <input type="hidden" name="old_rev" />
            <input type="submit" value="Voir les différences ..." title="Sélection des chemins et des révisions pour les différences" />
          </div>
        </form>
      </div>
    </div>
    <div id="altlinks">
      <h3>Télécharger en d'autres formats :</h3>
      <ul>
        <li class="last first">
          <a rel="nofollow" href="/hug/intranet-tma/trac/export/2519/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.field.inc">Format original</a>
        </li>
      </ul>
    </div>
    </div>
    <div id="footer" lang="en" xml:lang="en"><hr />
      <a id="tracpowered" href="http://trac.edgewall.org/"><img src="/hug/intranet-tma/trac/chrome/common/trac_logo_mini.png" height="30" width="107" alt="Trac Powered" /></a>
      <p class="left">Animé par <a href="/hug/intranet-tma/trac/about"><strong>Trac 0.12.3</strong></a><br />
        produit par <a href="http://www.edgewall.org/">Edgewall Software</a>.</p>
      <p class="right">En savoir plus sur le projet Trac :<br /> <a href="http://trac.edgewall.org/">http://trac.edgewall.org/</a></p>
    </div>
  </body>
</html>