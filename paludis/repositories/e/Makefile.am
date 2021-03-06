include $(top_srcdir)/misc/common-makefile.am

SUBDIRS = eapis ebuild .
DISTCLEANFILES = \
	e_repository_params-se.hh e_repository_params-se.cc \
	dep_parser-se.hh dep_parser-se.cc \
	iuse-se.hh iuse-se.cc

AM_CXXFLAGS = -I$(top_srcdir) -I$(top_builddir) @PALUDIS_CXXFLAGS@ @PALUDIS_CXXFLAGS_VISIBILITY@
DEFS= \
	-DSYSCONFDIR=\"$(sysconfdir)\" \
	-DLIBEXECDIR=\"$(libexecdir)\" \
	-DDATADIR=\"$(datadir)\" \
	-DLIBDIR=\"$(libdir)\"

noinst_LTLIBRARIES = libpaludiserepository.la

if ENABLE_XML
lib_LTLIBRARIES = libpaludiserepositoryxmlthings_@PALUDIS_PC_SLOT@.la
endif

noinst_HEADERS = \
	a_finder.hh \
	aa_visitor.hh \
	can_skip_phase.hh \
	check_fetched_files_visitor.hh \
	check_userpriv.hh \
	dep_parser.hh \
	dep_parser-se.hh \
	dep_parser-fwd.hh \
	do_fetch_action.hh \
	do_info_action.hh \
	do_install_action.hh \
	do_pretend_action.hh \
	do_pretend_fetch_action.hh \
	e_choice_value.hh \
	e_installed_repository.hh \
	e_installed_repository_id.hh \
	e_choices_key.hh \
	e_key.hh \
	e_keywords_key.hh \
	e_mask.hh \
	e_repository.hh \
	e_repository_exceptions.hh \
	e_repository_id.hh \
	e_repository_news.hh \
	e_repository_params-se.hh \
	e_repository_params.hh \
	e_repository_sets.hh \
	e_slot_key.hh \
	e_string_set_key.hh \
	e_stripper.hh \
	eapi.hh \
	eapi-fwd.hh \
	eapi_phase.hh \
	ebuild.hh \
	ebuild_flat_metadata_cache.hh \
	ebuild_id.hh \
	eclass_mtimes.hh \
	exheres_layout.hh \
	exheres_mask_store.hh \
	exheres_profile.hh \
	exndbam_id.hh \
	exndbam_repository.hh \
	extra_distribution_data.hh \
	fetch_visitor.hh \
	file_suffixes.hh \
	info_metadata_key.hh \
	iuse.hh \
	iuse-se.hh \
	pretend_fetch_visitor.hh \
	fix_locked_dependencies.hh \
	glsa.hh \
	layout.hh \
	licence_groups.hh \
	make_archive_strings.hh \
	make_use.hh \
	manifest2_reader.hh \
	mask_info.hh \
	memoised_hashes.hh \
	metadata_xml.hh \
	myoption.hh \
	myoptions_requirements_verifier.hh \
	parse_annotations.hh \
	parse_dependency_label.hh \
	parse_plain_text_label.hh \
	parse_uri_label.hh \
	pbin_merger.hh \
	permitted_directories.hh permitted_directories-fwd.hh \
	pipe_command_handler.hh \
	profile.hh \
	required_use_verifier.hh \
	source_uri_finder.hh \
	spec_tree_pretty_printer.hh \
	traditional_layout.hh \
	traditional_mask_file.hh \
	traditional_mask_store.hh \
	traditional_profile.hh \
	traditional_profile_file.hh \
	use_desc.hh \
	xml_things_handle.hh \
	vdb_contents_tokeniser.hh \
	vdb_id.hh \
	vdb_merger.hh \
	vdb_repository.hh \
	vdb_unmerger.hh

libpaludiserepository_la_SOURCES = \
	a_finder.cc \
	aa_visitor.cc \
	can_skip_phase.cc \
	check_fetched_files_visitor.cc \
	check_userpriv.cc \
	dep_parser.cc \
	do_fetch_action.cc \
	do_info_action.cc \
	do_install_action.cc \
	do_pretend_action.cc \
	do_pretend_fetch_action.cc \
	e_choice_value.cc \
	e_installed_repository.cc \
	e_installed_repository_id.cc \
	e_choices_key.cc \
	e_key.cc \
	e_keywords_key.cc \
	e_mask.cc \
	e_repository.cc \
	e_repository_exceptions.cc \
	e_repository_id.cc \
	e_repository_news.cc \
	e_repository_params.cc \
	e_repository_sets.cc \
	e_slot_key.cc \
	e_string_set_key.cc \
	e_stripper.cc \
	eapi.cc \
	eapi_phase.cc \
	ebuild.cc \
	ebuild_flat_metadata_cache.cc \
	ebuild_id.cc \
	eclass_mtimes.cc \
	exndbam_id.cc \
	exndbam_repository.cc \
	exheres_layout.cc \
	exheres_mask_store.cc \
	exheres_profile.cc \
	extra_distribution_data.cc \
	fetch_visitor.cc \
	file_suffixes.cc \
	info_metadata_key.cc \
	iuse.cc \
	pretend_fetch_visitor.cc \
	fix_locked_dependencies.cc \
	glsa.cc \
	layout.cc \
	licence_groups.cc \
	make_archive_strings.cc \
	make_use.cc \
	manifest2_reader.cc \
	mask_info.cc \
	memoised_hashes.cc \
	metadata_xml.cc \
	myoption.cc \
	myoptions_requirements_verifier.cc \
	parse_annotations.cc \
	parse_dependency_label.cc \
	parse_plain_text_label.cc \
	parse_uri_label.cc \
	pbin_merger.cc \
	permitted_directories.cc \
	pipe_command_handler.cc \
	profile.cc \
	registration.cc \
	required_use_verifier.cc \
	source_uri_finder.cc \
	spec_tree_pretty_printer.cc \
	traditional_layout.cc \
	traditional_mask_file.cc \
	traditional_mask_store.cc \
	traditional_profile.cc \
	traditional_profile_file.cc \
	use_desc.cc \
	xml_things_handle.cc \
	vdb_id.cc \
	vdb_merger.cc \
	vdb_repository.cc \
	vdb_unmerger.cc \
	$(noinst_HEADERS)

e_repository_TEST_SOURCES = e_repository_TEST.cc

e_repository_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

depend_rdepend_TEST_SOURCES = depend_rdepend_TEST.cc

depend_rdepend_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

depend_rdepend_TEST_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

depend_rdepend_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_ever_SOURCES = e_repository_TEST_ever.cc

e_repository_TEST_ever_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_ever_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_ever_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_exheres_0_SOURCES = e_repository_TEST_exheres_0.cc

e_repository_TEST_exheres_0_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_exheres_0_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_exheres_0_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_3_SOURCES = e_repository_TEST_3.cc

e_repository_TEST_3_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_3_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_3_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_4_SOURCES = e_repository_TEST_4.cc

e_repository_TEST_4_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_4_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_4_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_2_SOURCES = e_repository_TEST_2.cc

e_repository_TEST_2_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_2_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_2_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_1_SOURCES = e_repository_TEST_1.cc

e_repository_TEST_1_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_1_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_1_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_0_SOURCES = e_repository_TEST_0.cc

e_repository_TEST_0_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_0_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_0_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_phases_SOURCES = e_repository_TEST_phases.cc

e_repository_TEST_phases_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_phases_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_phases_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_exlibs_SOURCES = e_repository_TEST_exlibs.cc

e_repository_TEST_exlibs_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_exlibs_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_exlibs_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_replacing_SOURCES = e_repository_TEST_replacing.cc

e_repository_TEST_replacing_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_replacing_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_replacing_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

e_repository_TEST_symlink_rewriting_SOURCES = e_repository_TEST_symlink_rewriting.cc

e_repository_TEST_symlink_rewriting_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_symlink_rewriting_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_symlink_rewriting_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

vdb_repository_TEST_SOURCES = vdb_repository_TEST.cc

vdb_repository_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

vdb_repository_TEST_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

vdb_repository_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

vdb_repository_TEST_eapis_SOURCES = vdb_repository_TEST_eapis.cc

vdb_repository_TEST_eapis_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

vdb_repository_TEST_eapis_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

vdb_repository_TEST_eapis_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

vdb_repository_TEST_cache_SOURCES = vdb_repository_TEST_cache.cc

vdb_repository_TEST_cache_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

vdb_repository_TEST_cache_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

vdb_repository_TEST_cache_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

exndbam_repository_TEST_SOURCES = exndbam_repository_TEST.cc

exndbam_repository_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

exndbam_repository_TEST_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

exndbam_repository_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

vdb_merger_TEST_SOURCES = vdb_merger_TEST.cc

vdb_merger_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

vdb_merger_TEST_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

vdb_merger_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

vdb_unmerger_TEST_SOURCES = vdb_unmerger_TEST.cc

vdb_unmerger_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

vdb_unmerger_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

vdb_unmerger_TEST_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_sets_TEST_SOURCES = e_repository_sets_TEST.cc

e_repository_sets_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_sets_TEST_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_sets_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

dep_parser_TEST_SOURCES = dep_parser_TEST.cc

dep_parser_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

dep_parser_TEST_CXXFLAGS = $(AM_CXXFLAGS) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

dep_parser_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

aa_visitor_TEST_SOURCES = aa_visitor_TEST.cc

aa_visitor_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

aa_visitor_TEST_CXXFLAGS = $(AM_CXXFLAGS) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

aa_visitor_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

fetch_visitor_TEST_SOURCES = fetch_visitor_TEST.cc

fetch_visitor_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

fetch_visitor_TEST_CXXFLAGS = $(AM_CXXFLAGS) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

fetch_visitor_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

source_uri_finder_TEST_SOURCES = source_uri_finder_TEST.cc

source_uri_finder_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

source_uri_finder_TEST_CXXFLAGS = $(AM_CXXFLAGS) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

source_uri_finder_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

fix_locked_dependencies_TEST_SOURCES = fix_locked_dependencies_TEST.cc

fix_locked_dependencies_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

fix_locked_dependencies_TEST_CXXFLAGS = $(AM_CXXFLAGS) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

fix_locked_dependencies_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

ebuild_flat_metadata_cache_TEST_SOURCES = ebuild_flat_metadata_cache_TEST.cc

ebuild_flat_metadata_cache_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

ebuild_flat_metadata_cache_TEST_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

ebuild_flat_metadata_cache_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

EXTRA_DIST = \
	aa_visitor_TEST.cc \
	dep_parser.se \
	dep_parser-se.hh \
	dep_parser-se.cc \
	dep_parser_TEST.cc \
	depend_rdepend_TEST.cc \
	depend_rdepend_TEST_setup.sh \
	depend_rdepend_TEST_cleanup.sh \
	e_repository_TEST.cc \
	e_repository_TEST_setup.sh \
	e_repository_TEST_cleanup.sh \
	e_repository_TEST_ever.cc \
	e_repository_TEST_ever_setup.sh \
	e_repository_TEST_ever_cleanup.sh \
	e_repository_TEST_exheres_0.cc \
	e_repository_TEST_exheres_0_setup.sh \
	e_repository_TEST_exheres_0_cleanup.sh \
	e_repository_TEST_0.cc \
	e_repository_TEST_0_setup.sh \
	e_repository_TEST_0_cleanup.sh \
	e_repository_TEST_1.cc \
	e_repository_TEST_1_setup.sh \
	e_repository_TEST_1_cleanup.sh \
	e_repository_TEST_2.cc \
	e_repository_TEST_2_setup.sh \
	e_repository_TEST_2_cleanup.sh \
	e_repository_TEST_3.cc \
	e_repository_TEST_3_setup.sh \
	e_repository_TEST_3_cleanup.sh \
	e_repository_TEST_4.cc \
	e_repository_TEST_4_setup.sh \
	e_repository_TEST_4_cleanup.sh \
	e_repository_TEST_pbin.cc \
	e_repository_TEST_pbin_setup.sh \
	e_repository_TEST_pbin_cleanup.sh \
	e_repository_TEST_phases.cc \
	e_repository_TEST_phases_setup.sh \
	e_repository_TEST_phases_cleanup.sh \
	e_repository_TEST_exlibs.cc \
	e_repository_TEST_exlibs_setup.sh \
	e_repository_TEST_exlibs_cleanup.sh \
	e_repository_TEST_replacing.cc \
	e_repository_TEST_replacing_setup.sh \
	e_repository_TEST_replacing_cleanup.sh \
	e_repository_TEST_symlink_rewriting.cc \
	e_repository_TEST_symlink_rewriting_setup.sh \
	e_repository_TEST_symlink_rewriting_cleanup.sh \
	e_repository_params-se.hh \
	e_repository_params-se.cc \
	e_repository_params.se \
	e_repository_sets_TEST.cc \
	e_repository_sets_TEST_setup.sh \
	e_repository_sets_TEST_cleanup.sh \
	ebuild_flat_metadata_cache_TEST.cc \
	ebuild_flat_metadata_cache_TEST_setup.sh \
	ebuild_flat_metadata_cache_TEST_cleanup.sh \
	exndbam_repository_TEST.cc \
	exndbam_repository_TEST_setup.sh \
	exndbam_repository_TEST_cleanup.sh \
	fetch_visitor_TEST.cc \
	fetch_visitor_TEST_setup.sh \
	fetch_visitor_TEST_cleanup.sh \
	fix_locked_dependencies_TEST.cc \
	iuse.se \
	iuse-se.hh \
	iuse-se.cc \
	source_uri_finder_TEST.cc \
	xml_things_TEST.cc \
	xml_things_TEST_setup.sh \
	xml_things_TEST_cleanup.sh \
	vdb_repository_TEST.cc \
	vdb_repository_TEST_setup.sh \
	vdb_repository_TEST_cleanup.sh \
	vdb_repository_TEST_eapis.cc \
	vdb_repository_TEST_eapis_setup.sh \
	vdb_repository_TEST_eapis_cleanup.sh \
	vdb_repository_TEST_cache.cc \
	vdb_repository_TEST_cache_setup.sh \
	vdb_repository_TEST_cache_cleanup.sh \
	vdb_merger_TEST.cc \
	vdb_merger_TEST_setup.sh \
	vdb_merger_TEST_cleanup.sh \
	vdb_unmerger_TEST.cc \
	vdb_unmerger_TEST_setup.sh \
	vdb_unmerger_TEST_cleanup.sh

BUILT_SOURCES = \
	dep_parser-se.hh \
	dep_parser-se.cc \
	e_repository_params-se.hh \
	e_repository_params-se.cc \
	iuse-se.hh \
	iuse-se.cc

check_SCRIPTS = \
	depend_rdepend_TEST_setup.sh depend_rdepend_TEST_cleanup.sh \
	e_repository_TEST_setup.sh e_repository_TEST_cleanup.sh \
	e_repository_TEST_ever_setup.sh e_repository_TEST_ever_cleanup.sh \
	e_repository_TEST_exheres_0_setup.sh e_repository_TEST_exheres_0_cleanup.sh \
	e_repository_TEST_0_setup.sh e_repository_TEST_0_cleanup.sh \
	e_repository_TEST_1_setup.sh e_repository_TEST_1_cleanup.sh \
	e_repository_TEST_2_setup.sh e_repository_TEST_2_cleanup.sh \
	e_repository_TEST_3_setup.sh e_repository_TEST_3_cleanup.sh \
	e_repository_TEST_4_setup.sh e_repository_TEST_4_cleanup.sh \
	e_repository_TEST_pbin_setup.sh e_repository_TEST_pbin_cleanup.sh \
	e_repository_TEST_phases_setup.sh e_repository_TEST_phases_cleanup.sh \
	e_repository_TEST_exlibs_setup.sh e_repository_TEST_exlibs_cleanup.sh \
	e_repository_TEST_replacing_setup.sh e_repository_TEST_replacing_cleanup.sh \
	e_repository_TEST_symlink_rewriting_setup.sh e_repository_TEST_symlink_rewriting_cleanup.sh \
	xml_things_TEST_setup.sh xml_things_TEST_cleanup.sh \
	vdb_repository_TEST_setup.sh vdb_repository_TEST_cleanup.sh \
	vdb_repository_TEST_eapis_setup.sh vdb_repository_TEST_eapis_cleanup.sh \
	vdb_repository_TEST_cache_setup.sh vdb_repository_TEST_cache_cleanup.sh \
	exndbam_repository_TEST_setup.sh exndbam_repository_TEST_cleanup.sh \
	e_repository_sets_TEST_setup.sh e_repository_sets_TEST_cleanup.sh \
	fetch_visitor_TEST_setup.sh fetch_visitor_TEST_cleanup.sh

dep_parser-se.hh : dep_parser.se $(top_srcdir)/misc/make_se.bash
	if ! $(top_srcdir)/misc/make_se.bash --header $(srcdir)/dep_parser.se > $@ ; then rm -f $@ ; exit 1 ; fi

dep_parser-se.cc : dep_parser.se $(top_srcdir)/misc/make_se.bash
	if ! $(top_srcdir)/misc/make_se.bash --source $(srcdir)/dep_parser.se > $@ ; then rm -f $@ ; exit 1 ; fi

iuse-se.hh : iuse.se $(top_srcdir)/misc/make_se.bash
	if ! $(top_srcdir)/misc/make_se.bash --header $(srcdir)/iuse.se > $@ ; then rm -f $@ ; exit 1 ; fi

iuse-se.cc : iuse.se $(top_srcdir)/misc/make_se.bash
	if ! $(top_srcdir)/misc/make_se.bash --source $(srcdir)/iuse.se > $@ ; then rm -f $@ ; exit 1 ; fi

e_repository_params-se.hh : e_repository_params.se $(top_srcdir)/misc/make_se.bash
	if ! $(top_srcdir)/misc/make_se.bash --header $(srcdir)/e_repository_params.se > $@ ; then rm -f $@ ; exit 1 ; fi

e_repository_params-se.cc : e_repository_params.se $(top_srcdir)/misc/make_se.bash
	if ! $(top_srcdir)/misc/make_se.bash --source $(srcdir)/e_repository_params.se > $@ ; then rm -f $@ ; exit 1 ; fi

libpaludiserepositoryxmlthings_@PALUDIS_PC_SLOT@_la_SOURCES = xml_things.cc xml_things.hh
libpaludiserepositoryxmlthings_@PALUDIS_PC_SLOT@_la_CXXFLAGS = $(AM_CXXFLAGS) @LIBXML2DEPS_CFLAGS@

libpaludiserepositoryxmlthings_@PALUDIS_PC_SLOT@_la_LIBADD = \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	@LIBXML2DEPS_LIBS@

libpaludiserepositoryxmlthings_@PALUDIS_PC_SLOT@_la_LDFLAGS = -version-info @VERSION_LIB_CURRENT@:@VERSION_LIB_REVISION@:0

if ENABLE_XML

GLSA_TESTS = xml_things_TEST
xml_things_TEST_SOURCES = xml_things_TEST.cc

xml_things_TEST_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

xml_things_TEST_CXXFLAGS = $(AM_CXXFLAGS) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@
xml_things_TEST_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

endif

if ENABLE_PBINS

PBINS_TESTS = e_repository_TEST_pbin

e_repository_TEST_pbin_SOURCES = e_repository_TEST_pbin.cc

e_repository_TEST_pbin_LDADD = \
	$(top_builddir)/paludis/util/gtest_runner.o \
	$(top_builddir)/paludis/util/libpaludisutil_@PALUDIS_PC_SLOT@.la \
	$(top_builddir)/paludis/libpaludis_@PALUDIS_PC_SLOT@.la \
	$(DYNAMIC_LD_LIBS)

e_repository_TEST_pbin_CXXFLAGS = $(AM_CXXFLAGS) -I$(top_srcdir) @PALUDIS_CXXFLAGS_NO_DEBUGGING@ @GTESTDEPS_CXXFLAGS@

e_repository_TEST_pbin_LDFLAGS = @GTESTDEPS_LDFLAGS@ @GTESTDEPS_LIBS@

endif

paludis_datadir = $(datadir)/paludis

dist_paludis_data_DATA = traditional.exclude ebuild_entries_suffixes.conf

TESTS = \
	vdb_repository_TEST \
	vdb_repository_TEST_eapis \
	vdb_repository_TEST_cache \
	e_repository_TEST \
	e_repository_TEST_0 \
	e_repository_TEST_1 \
	e_repository_TEST_2 \
	e_repository_TEST_3 \
	e_repository_TEST_4 \
	e_repository_TEST_ever \
	e_repository_TEST_exheres_0 \
	e_repository_TEST_exlibs \
	e_repository_TEST_phases \
	e_repository_TEST_replacing \
	e_repository_TEST_symlink_rewriting \
	exndbam_repository_TEST \
	aa_visitor_TEST \
	dep_parser_TEST \
	depend_rdepend_TEST \
	e_repository_sets_TEST \
	ebuild_flat_metadata_cache_TEST \
	fetch_visitor_TEST \
	fix_locked_dependencies_TEST \
	source_uri_finder_TEST \
	vdb_merger_TEST \
	vdb_unmerger_TEST \
	$(GLSA_TESTS) \
	$(PBINS_TESTS)

check_PROGRAMS = $(TESTS)

