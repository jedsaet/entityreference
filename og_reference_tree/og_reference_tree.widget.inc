<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  
  

  


  <head>
    <title>
      og_reference_tree.widget.inc dans webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree.
     – hug - intranet-tma - Trac
    </title>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <!--[if IE]><script type="text/javascript">window.location.hash = window.location.hash;</script><![endif]-->
        <link rel="search" href="/hug/intranet-tma/trac/search" />
        <link rel="help" href="/hug/intranet-tma/trac/wiki/TracGuide" />
        <link rel="alternate" href="/hug/intranet-tma/trac/export/2519/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc" type="text/plain" title="Format original" />
        <link rel="tracwysiwyg.base" href="/hug/intranet-tma/trac" />
        <link rel="start" href="/hug/intranet-tma/trac/wiki" />
        <link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/trac.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/code.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/pygments/trac.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/browser.css" type="text/css" /><link rel="stylesheet" href="/hug/intranet-tma/trac/chrome/tracwysiwyg/wysiwyg.css" type="text/css" />
        <link rel="tracwysiwyg.stylesheet" href="/hug/intranet-tma/trac/chrome/common/css/trac.css" /><link rel="tracwysiwyg.stylesheet" href="/hug/intranet-tma/trac/chrome/tracwysiwyg/editor.css" />
        <link rel="prev" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc?rev=2214" title="Révision 2214" />
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
              <li class="first"><span>&larr; <a class="prev" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc?rev=2214" title="Révision 2214">Révision précédente</a></span></li><li><span class="missing">Révision suivante &rarr;</span></li><li><a href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc?annotate=blame" title="Annoter chaque ligne avec la révision de la dernière modification (ce procédé peut-être coûteux en temps...)">Annoter</a></li><li class="last"><a href="/hug/intranet-tma/trac/log/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc">Journal des révisions</a></li>
          </ul>
        <hr />
      </div>
    <div id="content" class="browser">
          <h1>
<a class="pathentry first" href="/hug/intranet-tma/trac/browser?order=name" title="Aller à la racine du dépôt">source:</a>
<a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory?order=name" title="Voir webfactory">webfactory</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk?order=name" title="Voir trunk">trunk</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites?order=name" title="Voir sites">sites</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all?order=name" title="Voir all">all</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules?order=name" title="Voir modules">modules</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom?order=name" title="Voir custom">custom</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree?order=name" title="Voir entity_reference_tree">entity_reference_tree</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree?order=name" title="Voir og_reference_tree">og_reference_tree</a><span class="pathentry sep">/</span><a class="pathentry" href="/hug/intranet-tma/trac/browser/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc?order=name" title="Voir og_reference_tree.widget.inc">og_reference_tree.widget.inc</a>
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
            <span title="7246 octets">7.1 KB</span>
            produite par fredrik.lahode, il y a <a class="timeline" href="/hug/intranet-tma/trac/timeline?from=2014-01-23T12%3A23%3A14%2B01%3A00&amp;precision=second" title="2014-01-23T12:23:14+01:00 dans « Activité »">4 mois</a>
            (<a href="/hug/intranet-tma/trac/changeset/2227/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc">différences</a>)</th>
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
        
  <table class="code"><thead><tr><th class="lineno" title="Numéros de lignes">Ligne</th><th class="content"> </th></tr></thead><tbody><tr><th id="L1"><a href="#L1">1</a></th><td>&lt;?php</td></tr><tr><th id="L2"><a href="#L2">2</a></th><td></td></tr><tr><th id="L3"><a href="#L3">3</a></th><td>/**</td></tr><tr><th id="L4"><a href="#L4">4</a></th><td> * Implements hook_field_widget_info().</td></tr><tr><th id="L5"><a href="#L5">5</a></th><td> */</td></tr><tr><th id="L6"><a href="#L6">6</a></th><td>function og_reference_tree_field_widget_info() {</td></tr><tr><th id="L7"><a href="#L7">7</a></th><td>  return array(</td></tr><tr><th id="L8"><a href="#L8">8</a></th><td>    'og_reference_tree' =&gt; array(</td></tr><tr><th id="L9"><a href="#L9">9</a></th><td>      'label' =&gt; t('OG reference tree'),</td></tr><tr><th id="L10"><a href="#L10">10</a></th><td>      'field types' =&gt; array('entityreference'),</td></tr><tr><th id="L11"><a href="#L11">11</a></th><td>      'behaviors' =&gt; array(</td></tr><tr><th id="L12"><a href="#L12">12</a></th><td>        'multiple values' =&gt; FIELD_BEHAVIOR_CUSTOM,</td></tr><tr><th id="L13"><a href="#L13">13</a></th><td>        'default value' =&gt; FIELD_BEHAVIOR_DEFAULT,</td></tr><tr><th id="L14"><a href="#L14">14</a></th><td>      ),</td></tr><tr><th id="L15"><a href="#L15">15</a></th><td>      'settings' =&gt; array(</td></tr><tr><th id="L16"><a href="#L16">16</a></th><td>        'start_minimized' =&gt; 0,</td></tr><tr><th id="L17"><a href="#L17">17</a></th><td>        'leaves_only' =&gt; 0,</td></tr><tr><th id="L18"><a href="#L18">18</a></th><td>        'filter_view' =&gt; '',</td></tr><tr><th id="L19"><a href="#L19">19</a></th><td>        'filter_view_arg_type' =&gt; 0,</td></tr><tr><th id="L20"><a href="#L20">20</a></th><td>        'filter_view_arg_key' =&gt; '',</td></tr><tr><th id="L21"><a href="#L21">21</a></th><td>        'select_parents' =&gt; 0,</td></tr><tr><th id="L22"><a href="#L22">22</a></th><td>        'cascading_selection' =&gt; 0,</td></tr><tr><th id="L23"><a href="#L23">23</a></th><td>        'track_list' =&gt; 0,</td></tr><tr><th id="L24"><a href="#L24">24</a></th><td>        'token_display' =&gt; '',</td></tr><tr><th id="L25"><a href="#L25">25</a></th><td>        'allowed_ids' =&gt; '',</td></tr><tr><th id="L26"><a href="#L26">26</a></th><td>        'parent_id' =&gt; '',</td></tr><tr><th id="L27"><a href="#L27">27</a></th><td>        'max_depth' =&gt; '',</td></tr><tr><th id="L28"><a href="#L28">28</a></th><td>      ),</td></tr><tr><th id="L29"><a href="#L29">29</a></th><td>    ),</td></tr><tr><th id="L30"><a href="#L30">30</a></th><td>  );</td></tr><tr><th id="L31"><a href="#L31">31</a></th><td>}</td></tr><tr><th id="L32"><a href="#L32">32</a></th><td></td></tr><tr><th id="L33"><a href="#L33">33</a></th><td>/**</td></tr><tr><th id="L34"><a href="#L34">34</a></th><td> * Implements hook_field_widget_settings_form().</td></tr><tr><th id="L35"><a href="#L35">35</a></th><td> */</td></tr><tr><th id="L36"><a href="#L36">36</a></th><td>function og_reference_tree_field_widget_settings_form($field, $instance) {</td></tr><tr><th id="L37"><a href="#L37">37</a></th><td>  $widget = $instance['widget'];</td></tr><tr><th id="L38"><a href="#L38">38</a></th><td>  $settings = $widget['settings'];</td></tr><tr><th id="L39"><a href="#L39">39</a></th><td>  $form = array();</td></tr><tr><th id="L40"><a href="#L40">40</a></th><td></td></tr><tr><th id="L41"><a href="#L41">41</a></th><td>  if ($widget['type'] == 'og_reference_tree') {</td></tr><tr><th id="L42"><a href="#L42">42</a></th><td>    $form['start_minimized'] = array(</td></tr><tr><th id="L43"><a href="#L43">43</a></th><td>      '#type' =&gt; 'checkbox',</td></tr><tr><th id="L44"><a href="#L44">44</a></th><td>      '#title' =&gt; t('Start minimized'),</td></tr><tr><th id="L45"><a href="#L45">45</a></th><td>      '#description' =&gt; t('Make the tree appear minimized on the form by default'),</td></tr><tr><th id="L46"><a href="#L46">46</a></th><td>      '#default_value' =&gt; $settings['start_minimized'],</td></tr><tr><th id="L47"><a href="#L47">47</a></th><td>      '#return_value' =&gt; 1,</td></tr><tr><th id="L48"><a href="#L48">48</a></th><td>    );</td></tr><tr><th id="L49"><a href="#L49">49</a></th><td></td></tr><tr><th id="L50"><a href="#L50">50</a></th><td>    $form['leaves_only'] = array(</td></tr><tr><th id="L51"><a href="#L51">51</a></th><td>      '#type' =&gt; 'checkbox',</td></tr><tr><th id="L52"><a href="#L52">52</a></th><td>      '#title' =&gt; t('Leaves only'),</td></tr><tr><th id="L53"><a href="#L53">53</a></th><td>      '#description' =&gt; t("Don't allow the user to select items that have children"),</td></tr><tr><th id="L54"><a href="#L54">54</a></th><td>      '#default_value' =&gt; $settings['leaves_only'],</td></tr><tr><th id="L55"><a href="#L55">55</a></th><td>      '#return_value' =&gt; 1,</td></tr><tr><th id="L56"><a href="#L56">56</a></th><td>    );</td></tr><tr><th id="L57"><a href="#L57">57</a></th><td></td></tr><tr><th id="L58"><a href="#L58">58</a></th><td>    $form['select_parents'] = array(</td></tr><tr><th id="L59"><a href="#L59">59</a></th><td>      '#type' =&gt; 'checkbox',</td></tr><tr><th id="L60"><a href="#L60">60</a></th><td>      '#title' =&gt; t('Select parents automatically'),</td></tr><tr><th id="L61"><a href="#L61">61</a></th><td>      '#description' =&gt; t("When turned on, this option causes the widget to automatically select the ancestors of all selected items. In Leaves Only mode, the parents will be added invisibly to the selected value.  &lt;em&gt;This option is only valid if an unlimited number of values can be selected.&lt;/em&gt;"),</td></tr><tr><th id="L62"><a href="#L62">62</a></th><td>      '#default_value' =&gt; $settings['select_parents'],</td></tr><tr><th id="L63"><a href="#L63">63</a></th><td>      '#element_validate' =&gt; array('_entity_reference_tree_select_parents_validate'),</td></tr><tr><th id="L64"><a href="#L64">64</a></th><td>      '#return_value' =&gt; 1,</td></tr><tr><th id="L65"><a href="#L65">65</a></th><td>    );</td></tr><tr><th id="L66"><a href="#L66">66</a></th><td></td></tr><tr><th id="L67"><a href="#L67">67</a></th><td>    $form['cascading_selection'] = array(</td></tr><tr><th id="L68"><a href="#L68">68</a></th><td>      '#type' =&gt; 'checkbox',</td></tr><tr><th id="L69"><a href="#L69">69</a></th><td>      '#title' =&gt; t('Cascading selection'),</td></tr><tr><th id="L70"><a href="#L70">70</a></th><td>      '#description' =&gt; t('On parent selection, automatically select children if none were selected. Some may then be manually unselected. In the same way, on parent unselection, unselect children if all were selected. &lt;em&gt;This option is only valid if an unlimited number of values can be selected.&lt;/em&gt;'),</td></tr><tr><th id="L71"><a href="#L71">71</a></th><td>      '#default_value' =&gt; $settings['cascading_selection'],</td></tr><tr><th id="L72"><a href="#L72">72</a></th><td>      '#element_validate' =&gt; array('_entity_reference_tree_cascading_selection_validate'),</td></tr><tr><th id="L73"><a href="#L73">73</a></th><td>      '#return_value' =&gt; 1,</td></tr><tr><th id="L74"><a href="#L74">74</a></th><td>    );</td></tr><tr><th id="L75"><a href="#L75">75</a></th><td></td></tr><tr><th id="L76"><a href="#L76">76</a></th><td>    $form['filter_view'] = array(</td></tr><tr><th id="L77"><a href="#L77">77</a></th><td>      '#type' =&gt; 'hidden',</td></tr><tr><th id="L78"><a href="#L78">78</a></th><td>      '#value' =&gt; $settings['filter_view'],</td></tr><tr><th id="L79"><a href="#L79">79</a></th><td>    );</td></tr><tr><th id="L80"><a href="#L80">80</a></th><td></td></tr><tr><th id="L81"><a href="#L81">81</a></th><td>    $form['filter_view_arg_type'] = array(</td></tr><tr><th id="L82"><a href="#L82">82</a></th><td>      '#type' =&gt; 'hidden',</td></tr><tr><th id="L83"><a href="#L83">83</a></th><td>      '#value' =&gt; $settings['filter_view_arg_type'],</td></tr><tr><th id="L84"><a href="#L84">84</a></th><td>    );</td></tr><tr><th id="L85"><a href="#L85">85</a></th><td>    </td></tr><tr><th id="L86"><a href="#L86">86</a></th><td>    $form['filter_view_arg_key'] = array(</td></tr><tr><th id="L87"><a href="#L87">87</a></th><td>      '#type' =&gt; 'hidden',</td></tr><tr><th id="L88"><a href="#L88">88</a></th><td>      '#value' =&gt; $settings['filter_view_arg_key'],</td></tr><tr><th id="L89"><a href="#L89">89</a></th><td>    );</td></tr><tr><th id="L90"><a href="#L90">90</a></th><td></td></tr><tr><th id="L91"><a href="#L91">91</a></th><td>    $form['token_display'] = array(</td></tr><tr><th id="L92"><a href="#L92">92</a></th><td>      '#type' =&gt; 'hidden',</td></tr><tr><th id="L93"><a href="#L93">93</a></th><td>      '#value' =&gt; $settings['token_display'],</td></tr><tr><th id="L94"><a href="#L94">94</a></th><td>    );</td></tr><tr><th id="L95"><a href="#L95">95</a></th><td></td></tr><tr><th id="L96"><a href="#L96">96</a></th><td>    $form['track_list'] = array(</td></tr><tr><th id="L97"><a href="#L97">97</a></th><td>      '#type' =&gt; 'checkbox',</td></tr><tr><th id="L98"><a href="#L98">98</a></th><td>      '#title' =&gt; t('Track list'),</td></tr><tr><th id="L99"><a href="#L99">99</a></th><td>      '#description' =&gt; t('Track what the user has chosen in a list below the tree. Useful when the tree is large, with many levels.'),</td></tr><tr><th id="L100"><a href="#L100">100</a></th><td>      '#default_value' =&gt; $settings['track_list'],</td></tr><tr><th id="L101"><a href="#L101">101</a></th><td>      '#return_value' =&gt; 1,</td></tr><tr><th id="L102"><a href="#L102">102</a></th><td>    );</td></tr><tr><th id="L103"><a href="#L103">103</a></th><td></td></tr><tr><th id="L104"><a href="#L104">104</a></th><td>    $form['max_depth'] = array(</td></tr><tr><th id="L105"><a href="#L105">105</a></th><td>      '#type' =&gt; 'textfield',</td></tr><tr><th id="L106"><a href="#L106">106</a></th><td>      '#title' =&gt; t('Maximum Depth'),</td></tr><tr><th id="L107"><a href="#L107">107</a></th><td>      '#description' =&gt; t("Only show items up to this many levels deep."),</td></tr><tr><th id="L108"><a href="#L108">108</a></th><td>      '#default_value' =&gt; $settings['max_depth'],</td></tr><tr><th id="L109"><a href="#L109">109</a></th><td>      '#size' =&gt; 2,</td></tr><tr><th id="L110"><a href="#L110">110</a></th><td>      '#return_value' =&gt; 1,</td></tr><tr><th id="L111"><a href="#L111">111</a></th><td>    );</td></tr><tr><th id="L112"><a href="#L112">112</a></th><td></td></tr><tr><th id="L113"><a href="#L113">113</a></th><td>    $form['parent_id'] = array(</td></tr><tr><th id="L114"><a href="#L114">114</a></th><td>      '#type' =&gt; 'textfield',</td></tr><tr><th id="L115"><a href="#L115">115</a></th><td>      '#title' =&gt; t('Parent OG group ID'),</td></tr><tr><th id="L116"><a href="#L116">116</a></th><td>      '#description' =&gt; t("Only show items underneath the OG group with this ID number. Leave this field blank to not limit OG group by parent."),</td></tr><tr><th id="L117"><a href="#L117">117</a></th><td>      '#default_value' =&gt; $settings['parent_id'],</td></tr><tr><th id="L118"><a href="#L118">118</a></th><td>      '#size' =&gt; 8,</td></tr><tr><th id="L119"><a href="#L119">119</a></th><td>      '#return_value' =&gt; 1,</td></tr><tr><th id="L120"><a href="#L120">120</a></th><td>    );</td></tr><tr><th id="L121"><a href="#L121">121</a></th><td>  }</td></tr><tr><th id="L122"><a href="#L122">122</a></th><td></td></tr><tr><th id="L123"><a href="#L123">123</a></th><td>  return $form;</td></tr><tr><th id="L124"><a href="#L124">124</a></th><td>}</td></tr><tr><th id="L125"><a href="#L125">125</a></th><td></td></tr><tr><th id="L126"><a href="#L126">126</a></th><td>/**</td></tr><tr><th id="L127"><a href="#L127">127</a></th><td> * Implements hook_field_widget_form().</td></tr><tr><th id="L128"><a href="#L128">128</a></th><td> */</td></tr><tr><th id="L129"><a href="#L129">129</a></th><td>function og_reference_tree_field_widget_form(&amp;$form, &amp;$form_state, $field, $instance, $langcode, $items, $delta, $element) {</td></tr><tr><th id="L130"><a href="#L130">130</a></th><td>  $settings = $instance['widget']['settings'];</td></tr><tr><th id="L131"><a href="#L131">131</a></th><td>  $value_key = key($field['columns']);</td></tr><tr><th id="L132"><a href="#L132">132</a></th><td>  $type = $instance['widget']['type'];</td></tr><tr><th id="L133"><a href="#L133">133</a></th><td></td></tr><tr><th id="L134"><a href="#L134">134</a></th><td>  $default_value = array();</td></tr><tr><th id="L135"><a href="#L135">135</a></th><td>  foreach ($items as $item) {</td></tr><tr><th id="L136"><a href="#L136">136</a></th><td>    $key = $item[$value_key];</td></tr><tr><th id="L137"><a href="#L137">137</a></th><td>    if ($key === 0) {</td></tr><tr><th id="L138"><a href="#L138">138</a></th><td>      $default_value[$key] = '0';</td></tr><tr><th id="L139"><a href="#L139">139</a></th><td>    }</td></tr><tr><th id="L140"><a href="#L140">140</a></th><td>    else {</td></tr><tr><th id="L141"><a href="#L141">141</a></th><td>      $default_value[$key] = $key;</td></tr><tr><th id="L142"><a href="#L142">142</a></th><td>    }</td></tr><tr><th id="L143"><a href="#L143">143</a></th><td>  }</td></tr><tr><th id="L144"><a href="#L144">144</a></th><td></td></tr><tr><th id="L145"><a href="#L145">145</a></th><td>  $multiple = $field['cardinality'] &gt; 1 || $field['cardinality'] == FIELD_CARDINALITY_UNLIMITED;</td></tr><tr><th id="L146"><a href="#L146">146</a></th><td>  $properties = array();</td></tr><tr><th id="L147"><a href="#L147">147</a></th><td></td></tr><tr><th id="L148"><a href="#L148">148</a></th><td>  if (!array_key_exists('#value', $element)) {</td></tr><tr><th id="L149"><a href="#L149">149</a></th><td>    $element['#value'] = array();</td></tr><tr><th id="L150"><a href="#L150">150</a></th><td>  }</td></tr><tr><th id="L151"><a href="#L151">151</a></th><td></td></tr><tr><th id="L152"><a href="#L152">152</a></th><td>  // A switch statement, in case we ever add more widgets to this module.</td></tr><tr><th id="L153"><a href="#L153">153</a></th><td>  switch ($instance['widget']['type']) {</td></tr><tr><th id="L154"><a href="#L154">154</a></th><td>    case 'og_reference_tree':</td></tr><tr><th id="L155"><a href="#L155">155</a></th><td>      $element['#field'] = 'og_reference_tree';</td></tr><tr><th id="L156"><a href="#L156">156</a></th><td>      $element['#attached']['js'] = array(drupal_get_path('module', 'entity_reference_tree') . '/entity_reference_tree.js');</td></tr><tr><th id="L157"><a href="#L157">157</a></th><td>      $element['#attached']['css'] = array(drupal_get_path('module', 'entity_reference_tree') . '/entity_reference_tree.css', drupal_get_path('module', 'og_reference_tree') . '/og_reference_tree.css');</td></tr><tr><th id="L158"><a href="#L158">158</a></th><td>      $element['#type'] = 'checkbox_tree';</td></tr><tr><th id="L159"><a href="#L159">159</a></th><td>      $element['#default_value'] = $multiple ? $default_value : array(reset($default_value) =&gt; reset($default_value));</td></tr><tr><th id="L160"><a href="#L160">160</a></th><td>      $element['#max_choices'] = $field['cardinality'];</td></tr><tr><th id="L161"><a href="#L161">161</a></th><td>      $element['#max_depth'] = $settings['max_depth'];</td></tr><tr><th id="L162"><a href="#L162">162</a></th><td>      $element['#start_minimized'] = $settings['start_minimized'];</td></tr><tr><th id="L163"><a href="#L163">163</a></th><td>      $element['#leaves_only'] = $settings['leaves_only'];</td></tr><tr><th id="L164"><a href="#L164">164</a></th><td>      $element['#filter_view'] = module_exists('views') ? $settings['filter_view'] : '';</td></tr><tr><th id="L165"><a href="#L165">165</a></th><td>      $element['#filter_view_arg_type'] = module_exists('views') ? $settings['filter_view_arg_type'] : '';</td></tr><tr><th id="L166"><a href="#L166">166</a></th><td>      $element['#filter_view_arg_key'] = module_exists('views') ? $settings['filter_view_arg_key'] : '';</td></tr><tr><th id="L167"><a href="#L167">167</a></th><td>      $element['#select_parents'] = $settings['select_parents'];</td></tr><tr><th id="L168"><a href="#L168">168</a></th><td>      $element['#cascading_selection'] = $settings['cascading_selection'];</td></tr><tr><th id="L169"><a href="#L169">169</a></th><td>      $element['#track_list'] = $settings['track_list'];</td></tr><tr><th id="L170"><a href="#L170">170</a></th><td>      $element['#allowed_ids'] = ($settings['allowed_ids'] &lt;&gt; '') ? explode(',', str_replace(" ", "", $settings['allowed_ids'])) : array();</td></tr><tr><th id="L171"><a href="#L171">171</a></th><td>      $element['#allowed_bundles']['entity_type'] = $field['settings']['target_type'];</td></tr><tr><th id="L172"><a href="#L172">172</a></th><td>      $element['#allowed_bundles']['bundle_names'] = $field['settings']['handler_settings']['target_bundles'];</td></tr><tr><th id="L173"><a href="#L173">173</a></th><td>      $element['#allowed_bundles']['#parent_id'] = $settings['parent_id'] ? $settings['parent_id'] : 0;</td></tr><tr><th id="L174"><a href="#L174">174</a></th><td>      $element['#token_display'] = module_exists('token') ? $settings['token_display'] : '';</td></tr><tr><th id="L175"><a href="#L175">175</a></th><td>      $element['#target_entity'] = $field['target_type'];</td></tr><tr><th id="L176"><a href="#L176">176</a></th><td>      break;</td></tr><tr><th id="L177"><a href="#L177">177</a></th><td>  }</td></tr><tr><th id="L178"><a href="#L178">178</a></th><td></td></tr><tr><th id="L179"><a href="#L179">179</a></th><td>  $element += array(</td></tr><tr><th id="L180"><a href="#L180">180</a></th><td>    '#value_key' =&gt; $value_key,</td></tr><tr><th id="L181"><a href="#L181">181</a></th><td>    '#element_validate' =&gt; array('_entity_reference_tree_widget_validate'),</td></tr><tr><th id="L182"><a href="#L182">182</a></th><td>    '#properties' =&gt; $properties,</td></tr><tr><th id="L183"><a href="#L183">183</a></th><td>  );</td></tr><tr><th id="L184"><a href="#L184">184</a></th><td></td></tr><tr><th id="L185"><a href="#L185">185</a></th><td>  return $element;</td></tr><tr><th id="L186"><a href="#L186">186</a></th><td>}</td></tr></tbody></table>

      </div>
      <div id="help"><strong>Note :</strong> consultez <a href="/hug/intranet-tma/trac/wiki/TracBrowser">TracBrowser</a> pour obtenir de l'aide sur l'utilisation de l'explorateur de sources.</div>
      <div id="anydiff">
        <form action="/hug/intranet-tma/trac/diff" method="get">
          <div class="buttons">
            <input type="hidden" name="new_path" value="/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc" />
            <input type="hidden" name="old_path" value="/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc" />
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
          <a rel="nofollow" href="/hug/intranet-tma/trac/export/2519/webfactory/trunk/sites/all/modules/custom/entity_reference_tree/og_reference_tree/og_reference_tree.widget.inc">Format original</a>
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