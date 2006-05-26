/*
*******************************************************************************
*   Copyright (C) 2005, International Business Machines
*   Corporation and others.  All Rights Reserved.
*******************************************************************************
*
*   file name:  udraft.h
*   encoding:   US-ASCII
*   tab size:   8 (not used)
*   indentation:4
*
*   Created by: gendraft.pl, a perl script written by Ram Viswanadha
*
*  Contains data for commenting out APIs.
*  Gets included by umachine.h
*
*  THIS FILE IS MACHINE-GENERATED, DON'T PLAY WITH IT IF YOU DON'T KNOW WHAT
*  YOU ARE DOING, OTHERWISE VERY BAD THINGS WILL HAPPEN!
*/

#ifndef UDRAFT_H
#define UDRAFT_H

#ifdef U_HIDE_DRAFT_API

#define ubrk_setUText_3_4 ubrk_setUText_DRAFT_API_DO_NOT_USE
#define ubrk_getRuleStatusVec_3_4 ubrk_getRuleStatusVec_DRAFT_API_DO_NOT_USE
#define ubrk_getLocaleByType_3_4 ubrk_getLocaleByType_DRAFT_API_DO_NOT_USE
#define ucal_getLocaleByType_3_4 ucal_getLocaleByType_DRAFT_API_DO_NOT_USE
#define UCaseMap_3_4 UCaseMap_DRAFT_API_DO_NOT_USE
#define ucasemap_open_3_4 ucasemap_open_DRAFT_API_DO_NOT_USE
#define ucasemap_close_3_4 ucasemap_close_DRAFT_API_DO_NOT_USE
#define ucasemap_getLocale_3_4 ucasemap_getLocale_DRAFT_API_DO_NOT_USE
#define ucasemap_getOptions_3_4 ucasemap_getOptions_DRAFT_API_DO_NOT_USE
#define ucasemap_setLocale_3_4 ucasemap_setLocale_DRAFT_API_DO_NOT_USE
#define ucasemap_setOptions_3_4 ucasemap_setOptions_DRAFT_API_DO_NOT_USE
#define ucasemap_utf8ToLower_3_4 ucasemap_utf8ToLower_DRAFT_API_DO_NOT_USE
#define ucasemap_utf8ToUpper_3_4 ucasemap_utf8ToUpper_DRAFT_API_DO_NOT_USE
#define UCHAR_S_TERM_3_4 UCHAR_S_TERM_DRAFT_API_DO_NOT_USE
#define UCHAR_VARIATION_SELECTOR_3_4 UCHAR_VARIATION_SELECTOR_DRAFT_API_DO_NOT_USE
#define UCHAR_NFD_INERT_3_4 UCHAR_NFD_INERT_DRAFT_API_DO_NOT_USE
#define UCHAR_NFKD_INERT_3_4 UCHAR_NFKD_INERT_DRAFT_API_DO_NOT_USE
#define UCHAR_NFC_INERT_3_4 UCHAR_NFC_INERT_DRAFT_API_DO_NOT_USE
#define UCHAR_NFKC_INERT_3_4 UCHAR_NFKC_INERT_DRAFT_API_DO_NOT_USE
#define UCHAR_SEGMENT_STARTER_3_4 UCHAR_SEGMENT_STARTER_DRAFT_API_DO_NOT_USE
#define UCHAR_PATTERN_SYNTAX_3_4 UCHAR_PATTERN_SYNTAX_DRAFT_API_DO_NOT_USE
#define UCHAR_PATTERN_WHITE_SPACE_3_4 UCHAR_PATTERN_WHITE_SPACE_DRAFT_API_DO_NOT_USE
#define UCHAR_POSIX_ALNUM_3_4 UCHAR_POSIX_ALNUM_DRAFT_API_DO_NOT_USE
#define UCHAR_POSIX_BLANK_3_4 UCHAR_POSIX_BLANK_DRAFT_API_DO_NOT_USE
#define UCHAR_POSIX_GRAPH_3_4 UCHAR_POSIX_GRAPH_DRAFT_API_DO_NOT_USE
#define UCHAR_POSIX_PRINT_3_4 UCHAR_POSIX_PRINT_DRAFT_API_DO_NOT_USE
#define UCHAR_POSIX_XDIGIT_3_4 UCHAR_POSIX_XDIGIT_DRAFT_API_DO_NOT_USE
#define UCHAR_NFD_QUICK_CHECK_3_4 UCHAR_NFD_QUICK_CHECK_DRAFT_API_DO_NOT_USE
#define UCHAR_NFKD_QUICK_CHECK_3_4 UCHAR_NFKD_QUICK_CHECK_DRAFT_API_DO_NOT_USE
#define UCHAR_NFC_QUICK_CHECK_3_4 UCHAR_NFC_QUICK_CHECK_DRAFT_API_DO_NOT_USE
#define UCHAR_NFKC_QUICK_CHECK_3_4 UCHAR_NFKC_QUICK_CHECK_DRAFT_API_DO_NOT_USE
#define UCHAR_LEAD_CANONICAL_COMBINING_CLASS_3_4 UCHAR_LEAD_CANONICAL_COMBINING_CLASS_DRAFT_API_DO_NOT_USE
#define UCHAR_TRAIL_CANONICAL_COMBINING_CLASS_3_4 UCHAR_TRAIL_CANONICAL_COMBINING_CLASS_DRAFT_API_DO_NOT_USE
#define UCHAR_GRAPHEME_CLUSTER_BREAK_3_4 UCHAR_GRAPHEME_CLUSTER_BREAK_DRAFT_API_DO_NOT_USE
#define UCHAR_SENTENCE_BREAK_3_4 UCHAR_SENTENCE_BREAK_DRAFT_API_DO_NOT_USE
#define UCHAR_WORD_BREAK_3_4 UCHAR_WORD_BREAK_DRAFT_API_DO_NOT_USE
#define UGraphemeClusterBreak_3_4 UGraphemeClusterBreak_DRAFT_API_DO_NOT_USE
#define UWordBreakValues_3_4 UWordBreakValues_DRAFT_API_DO_NOT_USE
#define USentenceBreak_3_4 USentenceBreak_DRAFT_API_DO_NOT_USE
#define U_LB_INSEPARABLE_3_4 U_LB_INSEPARABLE_DRAFT_API_DO_NOT_USE
#define ucnv_fromUCountPending_3_4 ucnv_fromUCountPending_DRAFT_API_DO_NOT_USE
#define ucnv_toUCountPending_3_4 ucnv_toUCountPending_DRAFT_API_DO_NOT_USE
#define ucol_openFromShortString_3_4 ucol_openFromShortString_DRAFT_API_DO_NOT_USE
#define ucol_getContractionsAndExpansions_3_4 ucol_getContractionsAndExpansions_DRAFT_API_DO_NOT_USE
#define ucol_openAvailableLocales_3_4 ucol_openAvailableLocales_DRAFT_API_DO_NOT_USE
#define ucol_getKeywords_3_4 ucol_getKeywords_DRAFT_API_DO_NOT_USE
#define ucol_getKeywordValues_3_4 ucol_getKeywordValues_DRAFT_API_DO_NOT_USE
#define ucol_getFunctionalEquivalent_3_4 ucol_getFunctionalEquivalent_DRAFT_API_DO_NOT_USE
#define ucol_getShortDefinitionString_3_4 ucol_getShortDefinitionString_DRAFT_API_DO_NOT_USE
#define ucol_normalizeShortDefinitionString_3_4 ucol_normalizeShortDefinitionString_DRAFT_API_DO_NOT_USE
#define ucol_getLocaleByType_3_4 ucol_getLocaleByType_DRAFT_API_DO_NOT_USE
#define ucol_cloneBinary_3_4 ucol_cloneBinary_DRAFT_API_DO_NOT_USE
#define ucol_openBinary_3_4 ucol_openBinary_DRAFT_API_DO_NOT_USE
#define UCURR_ALL_3_4 UCURR_ALL_DRAFT_API_DO_NOT_USE
#define UCURR_COMMON_3_4 UCURR_COMMON_DRAFT_API_DO_NOT_USE
#define UCURR_UNCOMMON_3_4 UCURR_UNCOMMON_DRAFT_API_DO_NOT_USE
#define UCURR_DEPRECATED_3_4 UCURR_DEPRECATED_DRAFT_API_DO_NOT_USE
#define UCURR_NON_DEPRECATED_3_4 UCURR_NON_DEPRECATED_DRAFT_API_DO_NOT_USE
#define UCurrCurrencyType_3_4 UCurrCurrencyType_DRAFT_API_DO_NOT_USE
#define ucurr_getDefaultFractionDigits_3_4 ucurr_getDefaultFractionDigits_DRAFT_API_DO_NOT_USE
#define ucurr_getRoundingIncrement_3_4 ucurr_getRoundingIncrement_DRAFT_API_DO_NOT_USE
#define ucurr_openISOCurrencies_3_4 ucurr_openISOCurrencies_DRAFT_API_DO_NOT_USE
#define UDAT_ERA_FIELD_3_4 UDAT_ERA_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_YEAR_FIELD_3_4 UDAT_YEAR_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_MONTH_FIELD_3_4 UDAT_MONTH_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_DATE_FIELD_3_4 UDAT_DATE_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_HOUR_OF_DAY1_FIELD_3_4 UDAT_HOUR_OF_DAY1_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_HOUR_OF_DAY0_FIELD_3_4 UDAT_HOUR_OF_DAY0_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_MINUTE_FIELD_3_4 UDAT_MINUTE_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_SECOND_FIELD_3_4 UDAT_SECOND_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_FRACTIONAL_SECOND_FIELD_3_4 UDAT_FRACTIONAL_SECOND_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_DAY_OF_WEEK_FIELD_3_4 UDAT_DAY_OF_WEEK_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_DAY_OF_YEAR_FIELD_3_4 UDAT_DAY_OF_YEAR_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_DAY_OF_WEEK_IN_MONTH_FIELD_3_4 UDAT_DAY_OF_WEEK_IN_MONTH_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_WEEK_OF_YEAR_FIELD_3_4 UDAT_WEEK_OF_YEAR_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_WEEK_OF_MONTH_FIELD_3_4 UDAT_WEEK_OF_MONTH_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_AM_PM_FIELD_3_4 UDAT_AM_PM_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_HOUR1_FIELD_3_4 UDAT_HOUR1_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_HOUR0_FIELD_3_4 UDAT_HOUR0_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_TIMEZONE_FIELD_3_4 UDAT_TIMEZONE_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_YEAR_WOY_FIELD_3_4 UDAT_YEAR_WOY_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_DOW_LOCAL_FIELD_3_4 UDAT_DOW_LOCAL_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_EXTENDED_YEAR_FIELD_3_4 UDAT_EXTENDED_YEAR_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_JULIAN_DAY_FIELD_3_4 UDAT_JULIAN_DAY_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_MILLISECONDS_IN_DAY_FIELD_3_4 UDAT_MILLISECONDS_IN_DAY_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_TIMEZONE_RFC_FIELD_3_4 UDAT_TIMEZONE_RFC_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_TIMEZONE_GENERIC_FIELD_3_4 UDAT_TIMEZONE_GENERIC_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_STANDALONE_DAY_FIELD_3_4 UDAT_STANDALONE_DAY_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_STANDALONE_MONTH_FIELD_3_4 UDAT_STANDALONE_MONTH_FIELD_DRAFT_API_DO_NOT_USE
#define UDAT_FIELD_COUNT_3_4 UDAT_FIELD_COUNT_DRAFT_API_DO_NOT_USE
#define UDateFormatField_3_4 UDateFormatField_DRAFT_API_DO_NOT_USE
#define udat_getLocaleByType_3_4 udat_getLocaleByType_DRAFT_API_DO_NOT_USE
#define UDataFileAccess_3_4 UDataFileAccess_DRAFT_API_DO_NOT_USE
#define udata_setFileAccess_3_4 udata_setFileAccess_DRAFT_API_DO_NOT_USE
#define UAcceptResult_3_4 UAcceptResult_DRAFT_API_DO_NOT_USE
#define uloc_setKeywordValue_3_4 uloc_setKeywordValue_DRAFT_API_DO_NOT_USE
#define uloc_acceptLanguageFromHTTP_3_4 uloc_acceptLanguageFromHTTP_DRAFT_API_DO_NOT_USE
#define uloc_acceptLanguage_3_4 uloc_acceptLanguage_DRAFT_API_DO_NOT_USE
#define ULocaleData_3_4 ULocaleData_DRAFT_API_DO_NOT_USE
#define ULocaleDataExemplarSetType_3_4 ULocaleDataExemplarSetType_DRAFT_API_DO_NOT_USE
#define ULocaleDataDelimiterType_3_4 ULocaleDataDelimiterType_DRAFT_API_DO_NOT_USE
#define UMeasurementSystem_3_4 UMeasurementSystem_DRAFT_API_DO_NOT_USE
#define ulocdata_open_3_4 ulocdata_open_DRAFT_API_DO_NOT_USE
#define ulocdata_close_3_4 ulocdata_close_DRAFT_API_DO_NOT_USE
#define ulocdata_setNoSubstitute_3_4 ulocdata_setNoSubstitute_DRAFT_API_DO_NOT_USE
#define ulocdata_getNoSubstitute_3_4 ulocdata_getNoSubstitute_DRAFT_API_DO_NOT_USE
#define ulocdata_getExemplarSet_3_4 ulocdata_getExemplarSet_DRAFT_API_DO_NOT_USE
#define ulocdata_getDelimiter_3_4 ulocdata_getDelimiter_DRAFT_API_DO_NOT_USE
#define ulocdata_getMeasurementSystem_3_4 ulocdata_getMeasurementSystem_DRAFT_API_DO_NOT_USE
#define ulocdata_getPaperSize_3_4 ulocdata_getPaperSize_DRAFT_API_DO_NOT_USE
#define umsg_autoQuoteApostrophe_3_4 umsg_autoQuoteApostrophe_DRAFT_API_DO_NOT_USE
#define UNUM_PATTERN_DECIMAL_3_4 UNUM_PATTERN_DECIMAL_DRAFT_API_DO_NOT_USE
#define UNUM_ORDINAL_3_4 UNUM_ORDINAL_DRAFT_API_DO_NOT_USE
#define UNUM_DURATION_3_4 UNUM_DURATION_DRAFT_API_DO_NOT_USE
#define UNUM_PATTERN_RULEBASED_3_4 UNUM_PATTERN_RULEBASED_DRAFT_API_DO_NOT_USE
#define UNUM_SIGNIFICANT_DIGITS_USED_3_4 UNUM_SIGNIFICANT_DIGITS_USED_DRAFT_API_DO_NOT_USE
#define UNUM_MIN_SIGNIFICANT_DIGITS_3_4 UNUM_MIN_SIGNIFICANT_DIGITS_DRAFT_API_DO_NOT_USE
#define UNUM_MAX_SIGNIFICANT_DIGITS_3_4 UNUM_MAX_SIGNIFICANT_DIGITS_DRAFT_API_DO_NOT_USE
#define UNUM_LENIENT_PARSE_3_4 UNUM_LENIENT_PARSE_DRAFT_API_DO_NOT_USE
#define UNUM_DEFAULT_RULESET_3_4 UNUM_DEFAULT_RULESET_DRAFT_API_DO_NOT_USE
#define UNUM_PUBLIC_RULESETS_3_4 UNUM_PUBLIC_RULESETS_DRAFT_API_DO_NOT_USE
#define UNUM_SIGNIFICANT_DIGIT_SYMBOL_3_4 UNUM_SIGNIFICANT_DIGIT_SYMBOL_DRAFT_API_DO_NOT_USE
#define unum_formatDoubleCurrency_3_4 unum_formatDoubleCurrency_DRAFT_API_DO_NOT_USE
#define unum_parseDoubleCurrency_3_4 unum_parseDoubleCurrency_DRAFT_API_DO_NOT_USE
#define unum_getLocaleByType_3_4 unum_getLocaleByType_DRAFT_API_DO_NOT_USE
#define URegularExpression_3_4 URegularExpression_DRAFT_API_DO_NOT_USE
#define UREGEX_CANON_EQ_3_4 UREGEX_CANON_EQ_DRAFT_API_DO_NOT_USE
#define uregex_open_3_4 uregex_open_DRAFT_API_DO_NOT_USE
#define uregex_openC_3_4 uregex_openC_DRAFT_API_DO_NOT_USE
#define uregex_close_3_4 uregex_close_DRAFT_API_DO_NOT_USE
#define uregex_clone_3_4 uregex_clone_DRAFT_API_DO_NOT_USE
#define uregex_pattern_3_4 uregex_pattern_DRAFT_API_DO_NOT_USE
#define uregex_flags_3_4 uregex_flags_DRAFT_API_DO_NOT_USE
#define uregex_setText_3_4 uregex_setText_DRAFT_API_DO_NOT_USE
#define uregex_getText_3_4 uregex_getText_DRAFT_API_DO_NOT_USE
#define uregex_matches_3_4 uregex_matches_DRAFT_API_DO_NOT_USE
#define uregex_lookingAt_3_4 uregex_lookingAt_DRAFT_API_DO_NOT_USE
#define uregex_find_3_4 uregex_find_DRAFT_API_DO_NOT_USE
#define uregex_findNext_3_4 uregex_findNext_DRAFT_API_DO_NOT_USE
#define uregex_groupCount_3_4 uregex_groupCount_DRAFT_API_DO_NOT_USE
#define uregex_group_3_4 uregex_group_DRAFT_API_DO_NOT_USE
#define uregex_start_3_4 uregex_start_DRAFT_API_DO_NOT_USE
#define uregex_end_3_4 uregex_end_DRAFT_API_DO_NOT_USE
#define uregex_reset_3_4 uregex_reset_DRAFT_API_DO_NOT_USE
#define uregex_replaceAll_3_4 uregex_replaceAll_DRAFT_API_DO_NOT_USE
#define uregex_replaceFirst_3_4 uregex_replaceFirst_DRAFT_API_DO_NOT_USE
#define uregex_appendReplacement_3_4 uregex_appendReplacement_DRAFT_API_DO_NOT_USE
#define uregex_appendTail_3_4 uregex_appendTail_DRAFT_API_DO_NOT_USE
#define uregex_split_3_4 uregex_split_DRAFT_API_DO_NOT_USE
#define ures_getLocaleByType_3_4 ures_getLocaleByType_DRAFT_API_DO_NOT_USE
#define ures_openAvailableLocales_3_4 ures_openAvailableLocales_DRAFT_API_DO_NOT_USE
#define USCRIPT_KATAKANA_OR_HIRAGANA_3_4 USCRIPT_KATAKANA_OR_HIRAGANA_DRAFT_API_DO_NOT_USE
#define USET_ADD_CASE_MAPPINGS_3_4 USET_ADD_CASE_MAPPINGS_DRAFT_API_DO_NOT_USE
#define uset_set_3_4 uset_set_DRAFT_API_DO_NOT_USE
#define uset_applyIntPropertyValue_3_4 uset_applyIntPropertyValue_DRAFT_API_DO_NOT_USE
#define uset_applyPropertyAlias_3_4 uset_applyPropertyAlias_DRAFT_API_DO_NOT_USE
#define uset_resemblesPattern_3_4 uset_resemblesPattern_DRAFT_API_DO_NOT_USE
#define uset_addAllCodePoints_3_4 uset_addAllCodePoints_DRAFT_API_DO_NOT_USE
#define uset_removeAll_3_4 uset_removeAll_DRAFT_API_DO_NOT_USE
#define uset_retain_3_4 uset_retain_DRAFT_API_DO_NOT_USE
#define uset_retainAll_3_4 uset_retainAll_DRAFT_API_DO_NOT_USE
#define uset_compact_3_4 uset_compact_DRAFT_API_DO_NOT_USE
#define uset_complementAll_3_4 uset_complementAll_DRAFT_API_DO_NOT_USE
#define uset_indexOf_3_4 uset_indexOf_DRAFT_API_DO_NOT_USE
#define uset_charAt_3_4 uset_charAt_DRAFT_API_DO_NOT_USE
#define uset_containsAll_3_4 uset_containsAll_DRAFT_API_DO_NOT_USE
#define uset_containsAllCodePoints_3_4 uset_containsAllCodePoints_DRAFT_API_DO_NOT_USE
#define uset_containsNone_3_4 uset_containsNone_DRAFT_API_DO_NOT_USE
#define uset_containsSome_3_4 uset_containsSome_DRAFT_API_DO_NOT_USE
#define uset_equals_3_4 uset_equals_DRAFT_API_DO_NOT_USE
#define UFILE_3_4 UFILE_DRAFT_API_DO_NOT_USE
#define UFileDirection_3_4 UFileDirection_DRAFT_API_DO_NOT_USE
#define u_fopen_3_4 u_fopen_DRAFT_API_DO_NOT_USE
#define u_finit_3_4 u_finit_DRAFT_API_DO_NOT_USE
#define u_fstropen_3_4 u_fstropen_DRAFT_API_DO_NOT_USE
#define u_fclose_3_4 u_fclose_DRAFT_API_DO_NOT_USE
#define u_feof_3_4 u_feof_DRAFT_API_DO_NOT_USE
#define u_fflush_3_4 u_fflush_DRAFT_API_DO_NOT_USE
#define u_frewind_3_4 u_frewind_DRAFT_API_DO_NOT_USE
#define u_fgetfile_3_4 u_fgetfile_DRAFT_API_DO_NOT_USE
#define u_fgetlocale_3_4 u_fgetlocale_DRAFT_API_DO_NOT_USE
#define u_fsetlocale_3_4 u_fsetlocale_DRAFT_API_DO_NOT_USE
#define u_fgetcodepage_3_4 u_fgetcodepage_DRAFT_API_DO_NOT_USE
#define u_fsetcodepage_3_4 u_fsetcodepage_DRAFT_API_DO_NOT_USE
#define u_fgetConverter_3_4 u_fgetConverter_DRAFT_API_DO_NOT_USE
#define u_fprintf_3_4 u_fprintf_DRAFT_API_DO_NOT_USE
#define u_vfprintf_3_4 u_vfprintf_DRAFT_API_DO_NOT_USE
#define u_fprintf_u_3_4 u_fprintf_u_DRAFT_API_DO_NOT_USE
#define u_vfprintf_u_3_4 u_vfprintf_u_DRAFT_API_DO_NOT_USE
#define u_fputs_3_4 u_fputs_DRAFT_API_DO_NOT_USE
#define u_fputc_3_4 u_fputc_DRAFT_API_DO_NOT_USE
#define u_file_write_3_4 u_file_write_DRAFT_API_DO_NOT_USE
#define u_fscanf_3_4 u_fscanf_DRAFT_API_DO_NOT_USE
#define u_vfscanf_3_4 u_vfscanf_DRAFT_API_DO_NOT_USE
#define u_fscanf_u_3_4 u_fscanf_u_DRAFT_API_DO_NOT_USE
#define u_vfscanf_u_3_4 u_vfscanf_u_DRAFT_API_DO_NOT_USE
#define u_fgets_3_4 u_fgets_DRAFT_API_DO_NOT_USE
#define u_fgetc_3_4 u_fgetc_DRAFT_API_DO_NOT_USE
#define u_fgetcx_3_4 u_fgetcx_DRAFT_API_DO_NOT_USE
#define u_fungetc_3_4 u_fungetc_DRAFT_API_DO_NOT_USE
#define u_file_read_3_4 u_file_read_DRAFT_API_DO_NOT_USE
#define u_fsettransliterator_3_4 u_fsettransliterator_DRAFT_API_DO_NOT_USE
#define u_sprintf_3_4 u_sprintf_DRAFT_API_DO_NOT_USE
#define u_snprintf_3_4 u_snprintf_DRAFT_API_DO_NOT_USE
#define u_vsprintf_3_4 u_vsprintf_DRAFT_API_DO_NOT_USE
#define u_vsnprintf_3_4 u_vsnprintf_DRAFT_API_DO_NOT_USE
#define u_sprintf_u_3_4 u_sprintf_u_DRAFT_API_DO_NOT_USE
#define u_snprintf_u_3_4 u_snprintf_u_DRAFT_API_DO_NOT_USE
#define u_vsprintf_u_3_4 u_vsprintf_u_DRAFT_API_DO_NOT_USE
#define u_vsnprintf_u_3_4 u_vsnprintf_u_DRAFT_API_DO_NOT_USE
#define u_sscanf_3_4 u_sscanf_DRAFT_API_DO_NOT_USE
#define u_vsscanf_3_4 u_vsscanf_DRAFT_API_DO_NOT_USE
#define u_sscanf_u_3_4 u_sscanf_u_DRAFT_API_DO_NOT_USE
#define u_vsscanf_u_3_4 u_vsscanf_u_DRAFT_API_DO_NOT_USE
#define UText_3_4 UText_DRAFT_API_DO_NOT_USE
#define UTextChunk_3_4 UTextChunk_DRAFT_API_DO_NOT_USE
#define UTextClone_3_4 UTextClone_DRAFT_API_DO_NOT_USE
#define UTextNativeLength_3_4 UTextNativeLength_DRAFT_API_DO_NOT_USE
#define UTextAccess_3_4 UTextAccess_DRAFT_API_DO_NOT_USE
#define UTextExtract_3_4 UTextExtract_DRAFT_API_DO_NOT_USE
#define UTextReplace_3_4 UTextReplace_DRAFT_API_DO_NOT_USE
#define UTextCopy_3_4 UTextCopy_DRAFT_API_DO_NOT_USE
#define UTextMapOffsetToNative_3_4 UTextMapOffsetToNative_DRAFT_API_DO_NOT_USE
#define UTextMapNativeIndexToUTF16_3_4 UTextMapNativeIndexToUTF16_DRAFT_API_DO_NOT_USE
#define UTextClose_3_4 UTextClose_DRAFT_API_DO_NOT_USE
#define utext_close_3_4 utext_close_DRAFT_API_DO_NOT_USE
#define utext_openUTF8_3_4 utext_openUTF8_DRAFT_API_DO_NOT_USE
#define utext_openUChars_3_4 utext_openUChars_DRAFT_API_DO_NOT_USE
#define utext_clone_3_4 utext_clone_DRAFT_API_DO_NOT_USE
#define utext_nativeLength_3_4 utext_nativeLength_DRAFT_API_DO_NOT_USE
#define utext_isLengthExpensive_3_4 utext_isLengthExpensive_DRAFT_API_DO_NOT_USE
#define utext_char32At_3_4 utext_char32At_DRAFT_API_DO_NOT_USE
#define utext_current32_3_4 utext_current32_DRAFT_API_DO_NOT_USE
#define utext_next32From_3_4 utext_next32From_DRAFT_API_DO_NOT_USE
#define utext_previous32From_3_4 utext_previous32From_DRAFT_API_DO_NOT_USE
#define utext_getNativeIndex_3_4 utext_getNativeIndex_DRAFT_API_DO_NOT_USE
#define utext_setNativeIndex_3_4 utext_setNativeIndex_DRAFT_API_DO_NOT_USE
#define utext_moveIndex32_3_4 utext_moveIndex32_DRAFT_API_DO_NOT_USE
#define utext_extract_3_4 utext_extract_DRAFT_API_DO_NOT_USE
#define utext_isWritable_3_4 utext_isWritable_DRAFT_API_DO_NOT_USE
#define utext_hasMetaData_3_4 utext_hasMetaData_DRAFT_API_DO_NOT_USE
#define utext_replace_3_4 utext_replace_DRAFT_API_DO_NOT_USE
#define utext_copy_3_4 utext_copy_DRAFT_API_DO_NOT_USE
#define utext_setup_3_4 utext_setup_DRAFT_API_DO_NOT_USE
#define UDTS_JAVA_TIME_3_4 UDTS_JAVA_TIME_DRAFT_API_DO_NOT_USE
#define UDTS_UNIX_TIME_3_4 UDTS_UNIX_TIME_DRAFT_API_DO_NOT_USE
#define UDTS_ICU4C_TIME_3_4 UDTS_ICU4C_TIME_DRAFT_API_DO_NOT_USE
#define UDTS_WINDOWS_FILE_TIME_3_4 UDTS_WINDOWS_FILE_TIME_DRAFT_API_DO_NOT_USE
#define UDTS_DOTNET_DATE_TIME_3_4 UDTS_DOTNET_DATE_TIME_DRAFT_API_DO_NOT_USE
#define UDTS_MAC_OLD_TIME_3_4 UDTS_MAC_OLD_TIME_DRAFT_API_DO_NOT_USE
#define UDTS_MAC_TIME_3_4 UDTS_MAC_TIME_DRAFT_API_DO_NOT_USE
#define UDTS_EXCEL_TIME_3_4 UDTS_EXCEL_TIME_DRAFT_API_DO_NOT_USE
#define UDTS_DB2_TIME_3_4 UDTS_DB2_TIME_DRAFT_API_DO_NOT_USE
#define UDTS_MAX_SCALE_3_4 UDTS_MAX_SCALE_DRAFT_API_DO_NOT_USE
#define UDateTimeScale_3_4 UDateTimeScale_DRAFT_API_DO_NOT_USE
#define UTSV_UNITS_VALUE_3_4 UTSV_UNITS_VALUE_DRAFT_API_DO_NOT_USE
#define UTSV_EPOCH_OFFSET_VALUE_3_4 UTSV_EPOCH_OFFSET_VALUE_DRAFT_API_DO_NOT_USE
#define UTSV_FROM_MIN_VALUE_3_4 UTSV_FROM_MIN_VALUE_DRAFT_API_DO_NOT_USE
#define UTSV_FROM_MAX_VALUE_3_4 UTSV_FROM_MAX_VALUE_DRAFT_API_DO_NOT_USE
#define UTSV_TO_MIN_VALUE_3_4 UTSV_TO_MIN_VALUE_DRAFT_API_DO_NOT_USE
#define UTSV_TO_MAX_VALUE_3_4 UTSV_TO_MAX_VALUE_DRAFT_API_DO_NOT_USE
#define UTSV_EPOCH_OFFSET_PLUS_1_VALUE_3_4 UTSV_EPOCH_OFFSET_PLUS_1_VALUE_DRAFT_API_DO_NOT_USE
#define UTSV_EPOCH_OFFSET_MINUS_1_VALUE_3_4 UTSV_EPOCH_OFFSET_MINUS_1_VALUE_DRAFT_API_DO_NOT_USE
#define UTimeScaleValue_3_4 UTimeScaleValue_DRAFT_API_DO_NOT_USE
#define utmscale_getTimeScaleValue_3_4 utmscale_getTimeScaleValue_DRAFT_API_DO_NOT_USE
#define utmscale_fromInt64_3_4 utmscale_fromInt64_DRAFT_API_DO_NOT_USE
#define utmscale_toInt64_3_4 utmscale_toInt64_DRAFT_API_DO_NOT_USE

#endif /* U_HIDE_DRAFT_API */
#endif /* UDRAFT_H */

