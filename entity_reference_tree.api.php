<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  
  

  


  <head>
    <title>
      entity_reference_tree.api.php dans webfactory/trunk/sites/all/modules/custom/entity_reference_tree.
     – hug - intranet-tma - Trac
    </title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <!--[if IE]><script type="text/javascript">window.location.hash = window.location.hash;</script><![endif]-->
        <link rel="search" href="/hug/intranet-tma/trac/search" />
        <link rel="help" href="/hug/intranet-tma/trac/wiki/TracGuide" />
        <link rel="alternate" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php?format=txt" type="text/plain" title="Texte brut" /><link rel="alternate" href="/hug/intranet-tma/trac/export/2519/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php" type="text/x-php; charset=utf-8" title="Format original" />
        <link rel="tracwysiwyg.base" href="/hug/intranet-tma/trac" />
        <link rel="start" href="/hug/intranet-tma/trac/wiki" />
        <link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/trac.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/code.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/pygments/trac.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/browser.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/tracwysiwyg/wysiwyg.css" type="text/css" />
        <link rel="tracwysiwyg.stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/trac.css" /><link rel="tracwysiwyg.stylesheet" href="/hug/intranet-tma/trac/chrome/tracwysiwyg/editor.css" />
        <link rel="prev" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php?rev=2161" title="Révision 2161" />
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
              <li class="first"><span>&larr; <a class="prev" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php?rev=2161" title="Révision 2161">Révision précédente</a></span></li><li><span class="missing">Révision suivante &rarr;</span></li><li><a href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php?annotate=blame" title="Annoter chaque ligne avec la révision de la dernière modification (ce procédé peut-être coûteux en temps...)">Annoter</a></li><li class="last"><a href="/hug/intranet-tma/trac/log/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php">Journal des révisions</a></li>
          </ul>
        <hr />
      </div>
    <div id="content" class="browser">
          <h1>
<a class="pathentry first" href="/hug/intranet-tma/trac/browser?order=name" title="Aller à la racine du dépôt">source:</a>
<a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory?order=name" title="Voir webfactory">webfactory</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk?order=name" title="Voir trunk">trunk</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites?order=name" title="Voir sites">sites</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all?order=name" title="Voir all">all</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules?order=name" title="Voir modules">modules</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom?order=name" title="Voir custom">custom</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree?order=name" title="Voir entity_reference_tree">entity_reference_tree</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php?order=name" title="Voir entity_reference_tree.api.php">entity_reference_tree.api.php</a>
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
          <th scope="col">Révision <a href="/hug/intranet-tma/trac/changeset/2227">2227</a>,
            <span title="408 octets">408 octets</span>
            produite par fredrik.lahode, il y a <a class="timeline" href="/hug/intranet-tma/trac/timeline?from=2014-01-23T12%3A23%3A14%2B01%3A00&amp;precision=second" title="2014-01-23T12:23:14+01:00 dans « Activité »">4 mois</a>
            (<a href="/hug/intranet-tma/trac/changeset/2227/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php">différences</a>)</th>
        </tr>
        <tr>
          <td class="message searchable">
              <p>
Corrections sur le module entityreference<br />
</p>
          </td>
        </tr>
      </table>
      <div id="preview" class="searchable">
        
  <table class="code"><thead><tr><th class="lineno" title="Numéros de lignes">Ligne</th><th class="content"> </th></tr></thead><tbody><tr><th id="L1"><a href="#L1">1</a></th><td><span class="cp">&lt;?php</span></td></tr><tr><th id="L2"><a href="#L2">2</a></th><td></td></tr><tr><th id="L3"><a href="#L3">3</a></th><td><span class="sd">/**</span></td></tr><tr><th id="L4"><a href="#L4">4</a></th><td><span class="sd"> * Retrieve a tree of an entity hierarchy</span></td></tr><tr><th id="L5"><a href="#L5">5</a></th><td><span class="sd"> *</span></td></tr><tr><th id="L6"><a href="#L6">6</a></th><td><span class="sd"> * @param $element</span></td></tr><tr><th id="L7"><a href="#L7">7</a></th><td><span class="sd"> *   The main checkbox_tree element.</span></td></tr><tr><th id="L8"><a href="#L8">8</a></th><td><span class="sd"> * @param $allowed_ids</span></td></tr><tr><th id="L9"><a href="#L9">9</a></th><td><span class="sd"> *   A list of allowed Ids</span></td></tr><tr><th id="L10"><a href="#L10">10</a></th><td><span class="sd"> * @param $label</span></td></tr><tr><th id="L11"><a href="#L11">11</a></th><td><span class="sd"> *   A list of allowed Ids</span></td></tr><tr><th id="L12"><a href="#L12">12</a></th><td><span class="sd"> *</span></td></tr><tr><th id="L13"><a href="#L13">13</a></th><td><span class="sd"> * @return</span></td></tr><tr><th id="L14"><a href="#L14">14</a></th><td><span class="sd"> *   A nested tree of entities</span></td></tr><tr><th id="L15"><a href="#L15">15</a></th><td><span class="sd"> */</span></td></tr><tr><th id="L16"><a href="#L16">16</a></th><td><span class="k">function</span> <span class="nf">hook_get_entity_hierarchy</span><span class="p">(</span><span class="nv">$element</span><span class="p">,</span> <span class="nv">$allowed_ids</span><span class="p">,</span> <span class="nv">$label</span> <span class="o">=</span> <span class="s1">''</span><span class="p">)</span> <span class="p">{</span></td></tr><tr><th id="L17"><a href="#L17">17</a></th><td><span class="p">}</span></td></tr><tr><th id="L18"><a href="#L18">18</a></th><td></td></tr><tr><th id="L19"><a href="#L19">19</a></th><td><span class="k">function</span> <span class="nf">hook_get_entity_parent</span><span class="p">(</span><span class="nv">$element</span><span class="p">,</span> <span class="nv">$entity_id</span><span class="p">)</span> <span class="p">{</span></td></tr><tr><th id="L20"><a href="#L20">20</a></th><td><span class="p">}</span></td></tr></tbody></table>

      </div>
      <div id="help"><strong>Note :</strong> consultez <a href="/hug/intranet-tma/trac/wiki/TracBrowser">TracBrowser</a> pour obtenir de l'aide sur l'utilisation de l'explorateur de sources.</div>
      <div id="anydiff">
        <form action="/hug/intranet-tma/trac/diff" method="get">
          <div class="buttons">
            <input type="hidden" name="new_path" value="/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php" />
            <input type="hidden" name="old_path" value="/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php" />
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
        <li class="first">
          <a rel="nofollow" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php?format=txt">Texte brut</a>
        </li><li class="last">
          <a rel="nofollow" href="/hug/intranet-tma/trac/export/2519/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/entity_reference_tree.api.php">Format original</a>
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