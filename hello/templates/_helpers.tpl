{{- define "hello.labels" -}}
app.kubernetes.io/name: {{ include "hello.name" . }}
app.kubernetes.io/instance: {{ .Release.Name }}
app.kubernetes.io/version: {{ .ChartAppVersion }}
app.kubernetes.io/managed-by: {{ .Release.Service }}
{{- end}}

{{- define "hello.name" -}}
{{- .Chart.Name | trunc 63 | trimSuffix "-" -}}
{{- end }}
